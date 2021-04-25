#include <stdio.h>
#include <stdlib.h>

double sum_vec4(double *v, size_t n) {
	double sum1 = 0.0, sum2 = 0.0, sum3 = 0.0, sum4 = 0.0;
	size_t i = 0;
	for (; i < n%4; i++) {
		sum1 += v[i];
	}
	#pragma novector
	#pragma nounroll
	for (; i < n; i+=4) {
		sum1 += v[i];
		sum2 += v[i+1];
		sum3 += v[i+2];
		sum4 += v[i+3];
	}
	return sum1+sum2+sum3+sum4;
}
