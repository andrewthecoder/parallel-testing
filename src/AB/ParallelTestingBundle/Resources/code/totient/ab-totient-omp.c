// Distributed and parallel technologies, Andrew Beveridge, 03/03/2014
// To Compile:		gcc -Wall -O -o totient-omp -fopenmp totient-omp.c
// To Run / Time:	/usr/bin/time -v ./totient-omp range_start range_end

#include <stdio.h>
#include <omp.h>

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

// Main method.
int main(int argc, char ** argv)
{
	// Load inputs
	long lower, upper, result;
	sscanf(argv[1], "%ld", &lower);
	sscanf(argv[2], "%ld", &upper);

	// Create parallelizable variables
	int i; result = 0.0;

	// Let's parallelize this shizzle
	#pragma omp parallel for default(shared) private(i) schedule(auto) reduction(+:result) num_threads(10)

	// Do the thing.
	for (i = lower; i <= upper; i++)
		result = result + getTotient(i);

	// Print the result
	printf("Sum of Totients between [%ld..%ld] is %ld \n", lower, upper, result);
	return 0;
}
