#include <stdio.h>
#include <stdlib.h>

double mul_vec10(double *v, size_t n) {
	double prod0 = 1.0, prod1 = 1.0, prod2 = 1.0;
	double prod3 = 1.0, prod4 = 1.0, prod5 = 1.0;
	double prod6 = 1.0, prod7 = 1.0, prod8 = 1.0, prod9 = 1.0;
	size_t i = 0;
	for (; i < n%10; i++) {
		prod0 *= v[i];
	}
	#pragma novector
	#pragma nounroll
	for (; i < n; i+=10) {
		prod0 *= v[i];
		prod1 *= v[i+1];
		prod2 *= v[i+2];
		prod3 *= v[i+3];
		prod4 *= v[i+4];
		prod5 *= v[i+5];
		prod6 *= v[i+6];
		prod7 *= v[i+7];
		prod8 *= v[i+8];
		prod9 *= v[i+9];
	}
	return prod0*prod1*prod2*prod3*prod4*prod5*prod6*prod7*prod8*prod9;
}
