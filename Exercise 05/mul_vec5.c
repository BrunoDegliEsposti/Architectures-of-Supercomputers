#include <stdio.h>
#include <stdlib.h>

double mul_vec5(double *v, size_t n) {
	double prod1 = 1.0, prod2 = 1.0, prod3 = 1.0, prod4 = 1.0, prod5 = 1.0;
	size_t i = 0;
	for (; i < n%5; i++) {
		prod1 *= v[i];
	}
	#pragma novector
	#pragma nounroll
	for (; i < n; i+=5) {
		prod1 *= v[i];
		prod2 *= v[i+1];
		prod3 *= v[i+2];
		prod4 *= v[i+3];
		prod5 *= v[i+4];
	}
	return prod1*prod2*prod3*prod4*prod5;
}
