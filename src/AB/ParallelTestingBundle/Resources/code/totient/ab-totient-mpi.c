// Distributed and parallel technologies, Andrew Beveridge, 03/03/2014
// To Compile:		mpicc -Wall -O -o totient-mpi totient-mpi.c
// To Run / Time:	/usr/bin/time -v mpirun -np N totient-mpi

#include <stdio.h>
#include <time.h>
#include <mpi.h>

clock_t stop, start;

long hcf(long x, long y)
{
  long t;

  while (y != 0) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}


// relprime x y = hcf x y == 1

int relprime(long x, long y)
{
  return hcf(x, y) == 1;
}

// totient(prime_number) = prime_number - 1
// totient(number) is even for numbers > 2 
// totient is multiplicative for relatively prime numbers so: totient(MN) = totient(M) * totient(N), where greatest_common_denominator(M, N) = 1
long getTotient (long number)
{
	long result, j;

    if(number == 1)
        return 1;

    result = number;

    // Check for divisibility by every prime number below the square root, starting with 2. 
    if(number % 2 == 0){
        result -= result / 2;
        do 
            number /= 2;
        while(number %2 == 0);
    }

    // Since this doesn't use a list of primes, check every odd number. Ideally, skip past composite numbers.
    for(j = 3; j * j <= number; j += 2){
        if(number %j == 0){
            result -= result / j;
            do 
                number /= j;
            while(number % j == 0);
        }
    }

    // If number > 1, then it's the last factor at this point. 
    if(number > 1) 
        result -= result / number;

    // Return the result. 
    return result; 
}

// Let's parallelize this shizzle
long getTotientRangeMPI(long arg_1, long arg_2, int ierr)
{
	MPI_Status status;
	long sum, partial_result;
	int my_id, root_process_id, i, num_rows, num_procs, helper,
		begin_at, finish_at, proc_id, avg_rows_per_process/*, sender */;

		sum = 0;

		root_process_id = 0;

		// Get process id and number of all MPI processes.
		ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
		ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

		// I must be the root process. POWER TO THE PEOPLE
		if(my_id == root_process_id){
			// if ((stop = clock()) == -1) {printf("Error while calling clock");};

			num_rows = (arg_2 - arg_1) + 1;

			avg_rows_per_process = num_rows / num_procs;

			// Distribute the rest of the numbers to other processes.
			for (proc_id = 1; proc_id < num_procs; ++proc_id)
			{
				// The last bit of the input array, might not be of avg_rows_per_process length.
				if(proc_id == (num_procs - 1)){
					begin_at = proc_id * avg_rows_per_process + arg_1;
					finish_at = arg_2;
					
					// Send start and end index of the last bit to the last process.
					ierr = MPI_Send(&begin_at, 1, MPI_INT, proc_id, 12345, MPI_COMM_WORLD);
					ierr = MPI_Send(&finish_at, 1, MPI_INT, proc_id, 12345, MPI_COMM_WORLD);
				}
				// Equal parts of avg_rows_per_process.
				else{
					begin_at = arg_1 + proc_id * avg_rows_per_process;
					finish_at = arg_1 + (proc_id + 1) * avg_rows_per_process - 1; 
					
					// Send them start and end index of their part of the computation.
					ierr = MPI_Send(&begin_at, 1, MPI_INT, proc_id, 12345, MPI_COMM_WORLD);
					ierr = MPI_Send(&finish_at, 1, MPI_INT, proc_id, 12345, MPI_COMM_WORLD);
				}
			}

			// Calculate the partial result (root).
			sum = 0;
			helper = arg_1;
			
			for(i = 0; i < avg_rows_per_process; i++)
				sum += getTotient(helper++);
				
			// Now shout at all the slaves to give us their moneys.
			for (proc_id = 1; proc_id < num_procs; ++proc_id){
				ierr = MPI_Recv(&partial_result, 1, MPI_LONG, MPI_ANY_SOURCE, 54321, MPI_COMM_WORLD, &status);
				// sender = status.MPI_SOURCE;
				sum += partial_result;
				// printf("Partial sum is: %ld, returned from process: %i.\n", partial_result, sender);
			}
			
			// We have all of the partial results added up, stop the clock and print the result.
			// printf("\n<-------------------------------------------------------->\n");
			// printf("GLOBAL SUM OF EULER TOTIENT NUMBERS FROM: %ld TO: %ld\nCALCULATED USING: %d PROCESSES IS: %ld.\n", arg_1, arg_2, num_procs, sum);
			// if ((stop = clock()) == -1) {printf("Error while calling clock");};
			// printf("TIME ELAPSED:%6.3f seconds (used by all the processes).\n", ((double)stop-start)/CLOCKS)
			// printf("<-------------------------------------------------------->\n\n");
		}
		// If we're here, we must be a slave.
		else{
			// Get the boundaries.
			ierr = MPI_Recv(&begin_at, 1, MPI_INT, root_process_id, 12345, MPI_COMM_WORLD, &status);
			ierr = MPI_Recv(&finish_at, 1, MPI_INT, root_process_id, 12345, MPI_COMM_WORLD, &status);

			partial_result = 0;

			// Calculate partial sum.
			for (i = begin_at; i <= finish_at; ++i)
				partial_result += getTotient(i);
			
			// printf("partial_result is:    %ld\n", partial_result);
			
			// Send the result back up the chain.
			ierr = MPI_Send(&partial_result, 1, MPI_LONG, root_process_id, 54321, MPI_COMM_WORLD);
		}

		ierr = MPI_Finalize();

		return sum;
}

int initialize()
{
	return MPI_Init(NULL, NULL);
}

// Main method.
int main(int argc, char ** argv)
{
	// MPI Init
	int ierr = initialize();

	// Load inputs
	long lower, upper, result;
	sscanf(argv[1], "%ld", &lower);
	sscanf(argv[2], "%ld", &upper);
	
	// Do the thing.
	result = getTotientRangeMPI(lower, upper, ierr);
	
	// Print the result
	printf("Sum of Totients between [%ld..%ld] is %ld \n", lower, upper, result);
	return 0;
}
