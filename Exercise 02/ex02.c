#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void init_vec(double *buf, size_t n);
double sum_vec1(double *v, size_t n);
double sum_vec2(double *v, size_t n);
double sum_vec3(double *v, size_t n);
double sum_vec4(double *v, size_t n);
double sum_vec8(double *v, size_t n);

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
	double runtime = 0, sum = 0;
	double t0, t1;
	for (r = 1; runtime < 0.1; r *= 2) {
		t0 = get_time();
		for (int i = 0; i < r; i++) {
			sum = sum_vec4(v, nelems);
		}
		t1 = get_time();
		assert(sum == nelems);
		runtime = t1-t0;
	}
	r = r/2;
	double gflops = 1e-9*(double)nelems*r/runtime;
	printf("Vector size: %zu doubles\n", nelems);
	printf("Sum repetitions: %d\n", r);
	printf("Runtime: %fs\n", runtime);
	printf("GFlop/s: %f\n", gflops);
	printf("Cycles per flop: %f\n", 2.2/gflops);
	return 0;
}
