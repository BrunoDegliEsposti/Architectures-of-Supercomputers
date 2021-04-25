#include <stdio.h>
#include <stdlib.h>

double sum_vec8(double *v, size_t n) {
	double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	double sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
	size_t i = 0;
	for (; i < n%8; i++) {
		sum1 += v[i];
	}
	#pragma novector
	#pragma nounroll
	for (; i < n; i+=8) {
		sum1 += v[i];
		sum2 += v[i+1];
		sum3 += v[i+2];
		sum4 += v[i+3];
		sum5 += v[i+4];
		sum6 += v[i+5];
		sum7 += v[i+6];
		sum8 += v[i+7];
	}
	return sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8;
}
