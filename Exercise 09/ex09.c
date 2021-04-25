#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <omp.h>

double sum_auto(double *v, size_t n);

double get_time(void) {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    return (double)a.tv_sec + (double)a.tv_nsec * 1e-9;
}

int main(int argc, char **argv) {
	// Parse input, rounding nbytes if necessary
	if (argc != 2) {
		return 1;
	}
	int nthreads;
	#pragma omp parallel
	{
		#pragma omp single
		nthreads = omp_get_num_threads();
	}
	size_t nbytes, nelems;
	sscanf(argv[1], "%zu", &nbytes);
	nelems = nbytes / sizeof(double);
	size_t nelems_per_thread = nelems / nthreads;
	nelems = nelems_per_thread * nthreads;
	nbytes = nelems * sizeof(double);

	// Initialize vector
	double *v = malloc(nbytes);
	#pragma omp parallel for
	for (size_t i = 0; i < nelems; i++) {
		v[i] = 1.0;
	}

	// Benchmark the parallel sum
	int repetitions = 1;
	double t0, t1, runtime;
	while (1) {
		double sum = 0;
		t0 = get_time();
		#pragma omp parallel reduction(+:sum)
		{
			int thread_id = omp_get_thread_num();
			for (int i = 0; i < repetitions; i++) {
				sum = sum_auto(&v[thread_id*nelems_per_thread], nelems_per_thread);
			}
		}
		t1 = get_time();
		assert(sum == nelems);
		runtime = t1-t0;
		if (runtime >= 1) {
			break;
		}
		else {
			repetitions *= 2;
		}
	}
	double gflops = 1e-9*(double)nelems*repetitions/runtime;
	double kb_per_thread = (double)nelems_per_thread*sizeof(double)/1024;
	//printf("Number of threads: %d\n", nthreads);
	//printf("Workload per thread: %f KB\n", kb_per_thread);
	//printf("Sum repetitions: %d\n", repetitions);
	//printf("Runtime: %f s\n", runtime);
	//printf("GFlop/s: %f\n", gflops);
	printf("%d, %f\n", nthreads, gflops);
	return 0;
}
