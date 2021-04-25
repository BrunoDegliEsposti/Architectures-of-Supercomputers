#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void init_vec(double *v, size_t n);
double sum_intrinsics1(double *v, size_t n);
double sum_intrinsics4(double *v, size_t n);
double sum_auto(double *v, size_t n);

double get_time(void) {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    return (double)a.tv_sec + (double)a.tv_nsec * 1e-9;
}

int main(int argc, char **argv) {
	FILE *f = fopen("input_sizes.txt","r");
	size_t nkbytes;

	while (1 == fscanf(f," %zu ", &nkbytes))
	{
		size_t nbytes = 1024 * nkbytes;
		size_t nelems = nbytes / sizeof(double);
		double *v = NULL;
		posix_memalign((void**)&v, 32, nbytes); // 256-bits alignment
		init_vec(v, nelems);
		
		double runtime = 0, t0, t1;
		double sum = 0;
		int r;
		for (r = 1; runtime < 0.1; r *= 2) {
			t0 = get_time();
			for (int i = 0; i < r; i++) {
				sum = sum_intrinsics4(v, nelems);
			}
			t1 = get_time();
			assert(sum == nelems);
			runtime = t1-t0;
		}
		r = r/2;
		double mflops = 1e-6*(double)nelems*r/runtime;
		//printf("Vector size: %zu kb\n", nkbytes);
		//printf("MFlop/s: %f\n", mflops);
		//printf("Flops per cycle: %f\n", mflops/2200);
		printf("%zu, %f\n", nkbytes, mflops);
		free(v);
	}

	fclose(f);
	return 0;
}
