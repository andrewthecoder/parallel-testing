// Distributed and parallel technologies, Andrew Beveridge, 03/03/2014
// To Compile:		mpicc -Wall -O -o ab-totient-mpi ab-totient-mpi.c
// To Run / Time:	/usr/bin/time -v mpirun -np N ab-totient-mpi

#include <stdio.h>
#include <mpi.h>

/* 	When input is a prime number, the totient is simply the prime number - 1. Totient is always even (except for 1).
	If n is a positive integer, then φ(n) is the number of integers k in the range 1 ≤ k ≤ n for which gcd(n, k) = 1  */
long getTotient (long number) {
	long result = number;

    // Check every prime number below the square root for divisibility
    if(number % 2 == 0){
        result -= result / 2;
        do 
            number /= 2;
        while(number %2 == 0);
    }

    // Primitive replacement for a list of primes, looping through every odd number
    long prime;
	for(prime = 3; prime * prime <= number; prime += 2){
        if(number %prime == 0){
            result -= result / prime;
            do 
                number /= prime;
            while(number % prime == 0);
        }
    }
	
    // Last common factor 
    if(number > 1) 
        result -= result / number;

    // Return the result. 
    return result; 
}

// Why is MPI so much more hassle than OpenMP D:
long getTotientRangeMPI(long lower, long upper, int mpihandle) {
	MPI_Status status;
	long sum, partial_result;
	int this_process_id, root_process_id, i, range, num_procs, helper, begin_at, finish_at, proc_id, avg_totients_per_process;

		sum = 0;
		root_process_id = 0;

		// Get process id and number of all MPI processes.
		mpihandle = MPI_Comm_rank(MPI_COMM_WORLD, &this_process_id);
		mpihandle = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

		// If I'm the root process then I guess I'll be doing all the talking. I hate talking.
		if(this_process_id == root_process_id) {
			range = (upper - lower) + 1;
			avg_totients_per_process = range / num_procs;

			// Send numbers to each process
			for (proc_id = 1; proc_id < num_procs; ++proc_id) {
				// Input range probably doesn't divide neatly by the number of processes. Handle it.
				if(proc_id == (num_procs - 1)){
					begin_at = proc_id * avg_totients_per_process + lower;
					finish_at = upper;
					
					// Send start and end index of the last bit to the last process.
					mpihandle = MPI_Send(&begin_at, 1, MPI_INT, proc_id, 12345, MPI_COMM_WORLD);
					mpihandle = MPI_Send(&finish_at, 1, MPI_INT, proc_id, 12345, MPI_COMM_WORLD);
				} else {
					// Equal shares of work for everybody. Who needs capitalism anyway?
					begin_at = lower + proc_id * avg_totients_per_process;
					finish_at = lower + (proc_id + 1) * avg_totients_per_process - 1;
					
					// Send start and end index of respective snippet of work.
					mpihandle = MPI_Send(&begin_at, 1, MPI_INT, proc_id, 12345, MPI_COMM_WORLD);
					mpihandle = MPI_Send(&finish_at, 1, MPI_INT, proc_id, 12345, MPI_COMM_WORLD);
				}
			}

			// Do our part for the cause, to show we are a strong and mighty leader!
			sum = 0;
			helper = lower;
			
			for(i = 0; i < avg_totients_per_process; i++)
				sum += getTotient(helper++);
				
			// Now shout at all the slaves to give us their moneys. Did I say slaves? I mean fairly paid workers, of course.
			for (proc_id = 1; proc_id < num_procs; ++proc_id) {
				mpihandle = MPI_Recv(&partial_result, 1, MPI_LONG, MPI_ANY_SOURCE, 54321, MPI_COMM_WORLD, &status);
				sum += partial_result;
				// printf("Partial sum is: %ld, from process: %i.\n", partial_result, sender);
			}
			
			// We have all of the partial results added up
			// printf("GLOBAL SUM OF EULER TOTIENT NUMBERS FROM: %ld TO: %ld\nCALCULATED USING: %d PROCESSES IS: %ld.\n", lower, upper, num_procs, sum);
		
		} else {
			// If we're here, we must be a slave. I mean, worker. I have rights dammit!
			
			// Get the boundaries.
			mpihandle = MPI_Recv(&begin_at, 1, MPI_INT, root_process_id, 12345, MPI_COMM_WORLD, &status);
			mpihandle = MPI_Recv(&finish_at, 1, MPI_INT, root_process_id, 12345, MPI_COMM_WORLD, &status);

			partial_result = 0;

			// Calculate partial sum.
			for (i = begin_at; i <= finish_at; ++i)
				partial_result += getTotient(i);
				// printf("Partial sum is: %ld\n", partial_result);
			
			// Send the result back up to daddy. All hail the king!
			mpihandle = MPI_Send(&partial_result, 1, MPI_LONG, root_process_id, 54321, MPI_COMM_WORLD);
		}

		// Tidy up after ourselves
		mpihandle = MPI_Finalize();
		return sum;
}

int initialize() {
	return MPI_Init(NULL, NULL);
}

// Main method.
int main(int argc, char ** argv) {
	// Load inputs
	long lower, upper, result;
	sscanf(argv[1], "%ld", &lower);
	sscanf(argv[2], "%ld", &upper);
	
	// Initialize MPI
	int mpihandle = initialize();

	// Pass the parameters down to our MPI distributor
	result = getTotientRangeMPI(lower, upper, mpihandle);
	
	// Print the result
	printf("Sum of Totients between [%ld..%ld] is %ld \n", lower, upper, result);
	return 0;
}
