#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>

double cache_access_doubles(double *v,
	size_t nelems, unsigned int line_size);

int main(int argc, char **argv) {
	LIKWID_MARKER_INIT;
	if (argc != 2) {
		return 1;
	}
	size_t nbytes;
	sscanf(argv[1], "%zu", &nbytes);
	size_t nelems = nbytes/sizeof(double);
	double *v = malloc(nelems * sizeof(double));
	for (int i = 0; i < nelems; i++) {
		v[i] = 1.0;
	}

	unsigned int cache_size = 32*1024;
	unsigned int nsets = 64;
	unsigned int associativity = 8;
	unsigned int line_size = 64;

	LIKWID_MARKER_START("Compute");
	for (int i = 0; i < 10000; i++) {
		cache_access_doubles(v, nelems, line_size);
	}
	LIKWID_MARKER_STOP("Compute");
	LIKWID_MARKER_CLOSE;
	return 0;
}
