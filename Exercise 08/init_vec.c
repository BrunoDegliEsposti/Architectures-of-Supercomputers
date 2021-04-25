#include <stdio.h>
#include <stdlib.h>

void init_vec(double *v, size_t n) {
	for (size_t i = 0; i < n; i++) {
		v[i] = 1.0;
	}
}
