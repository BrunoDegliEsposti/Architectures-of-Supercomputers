#include <stdio.h>
#include <stdlib.h>

double sum_auto(double *v, size_t n) {
	double sum = 0.0;
	for (size_t i = 0; i < n; i++) {
		sum += v[i];
	}
	return sum;
}
