#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_buf(double *buf, size_t len);

double get_time(void) {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    return (double)a.tv_sec + (double)a.tv_nsec * 1e-9;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		return 1;
	}
	size_t n = atoll(argv[1]);
	double *buf = malloc(n);
	double t0 = get_time();
	init_buf(buf, n/sizeof(double));
	double t1 = get_time();
	double membdw = (double)n*1e-9/(t1-t0);
	printf("Memory bandwidth: %f GB/s\n", membdw);
	return 0;
}
