#include <stdio.h>
#include <stdlib.h>

double sum_vec1(double *v, size_t n) {
	double sum = 0.0;
	#pragma novector
	#pragma nounroll
	for (size_t i = 0; i < n; i++) {
		sum += v[i];
	}
	return sum;
}
