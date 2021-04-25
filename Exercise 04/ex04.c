#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <likwid.h>

void init_vec(int *v, size_t len);
double benchmark(int *v, size_t len);
double benchmark_nobranch(int *v, size_t len);

double get_time(void) {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    return (double)a.tv_sec + (double)a.tv_nsec * 1e-9;
}

int main(int argc, char **argv) {
	LIKWID_MARKER_INIT;
	size_t nelems = 1000000;
	size_t nbytes = nelems * sizeof(int);
	int *v = malloc(nbytes);
	init_vec(v, nelems);

	int r;
	double runtime = 0;
	double t0, t1;
	LIKWID_MARKER_START("Compute");
	for (r = 1; runtime < 0.1; r *= 2) {
		t0 = get_time();
		for (int i = 0; i < r; i++) {
			benchmark(v, nelems);
		}
		t1 = get_time();
		runtime = t1-t0;
	}
	LIKWID_MARKER_STOP("Compute");
	r = r/2;
	double cycles_per_loop = 2.2e9*runtime/((double)nelems*r);
	printf("Execution time of one loop: %f cycles\n", cycles_per_loop);
	LIKWID_MARKER_CLOSE;
	return 0;
}
