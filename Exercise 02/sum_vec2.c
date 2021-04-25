#include <stdio.h>
#include <stdlib.h>

double sum_vec2(double *v, size_t n) {
	double sum1 = 0.0;
	double sum2 = 0.0;
	size_t i = 0;
	for (; i < n%2; i++) {
		sum1 += v[i];
	}
	#pragma novector
	#pragma nounroll
	for (; i < n; i+=2) {
		sum1 += v[i];
		sum2 += v[i+1];
	}
	return sum1+sum2;
}
