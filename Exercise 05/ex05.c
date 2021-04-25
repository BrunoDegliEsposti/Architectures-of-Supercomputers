#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void init_vec(double *buf, size_t n);
double mul_vec1(double *v, size_t n);
double mul_vec5(double *v, size_t n);
double mul_vec10(double *v, size_t n);

double get_time(void) {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    return (double)a.tv_sec + (double)a.tv_nsec * 1e-9;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		return 1;
	}
	size_t nbytes, nelems;
	sscanf(argv[1], "%zu", &nbytes);
	nelems = nbytes / sizeof(double);
	nbytes = nelems * sizeof(double);
	double *v = malloc(nbytes);
	init_vec(v, nelems);

	int r;
	double prod = 1.0;
	double runtime = 0, t0 = 0, t1 = 0;
	for (r = 1; runtime < 0.1; r *= 2) {
		t0 = get_time();
		for (int i = 0; i < r; i++) {
			prod = mul_vec1(v, nelems);
		}
		t1 = get_time();
		assert(prod == 1.0);
		runtime = t1-t0;
	}
	r = r/2;
	double gflops = 1e-9*(double)nelems*r/runtime;
	printf("Vector size: %zu doubles\n", nelems);
	printf("Product repetitions: %d\n", r);
	printf("Runtime: %fs\n", runtime);
	printf("GFlop/s: %f\n", gflops);
	printf("Cycles per flop: %f\n", 2.2/gflops);
	return 0;
}
