#include <stdio.h>
#include <stdlib.h>

double mul_vec1(double *v, size_t n) {
	double prod = 1.0;
	#pragma novector
	#pragma nounroll
	for (size_t i = 0; i < n; i++) {
		prod *= v[i];
	}
	return prod;
}
