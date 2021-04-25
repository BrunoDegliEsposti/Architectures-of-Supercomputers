#include <stdio.h>
#include <stdlib.h>
#include "x86intrin.h"

double sum_intrinsics1(double const *v, size_t n) {
	__m256d sum = _mm256_setzero_pd();
	__m256d pd;
	double sd[4];
	size_t i;
	size_t nrounded = n - (n%4);
	#pragma novector
	#pragma nounroll
	for (i = 0; i < nrounded; i+=4) {
		pd = _mm256_loadu_pd(&v[i]);
		sum = _mm256_add_pd(sum, pd);
	}
	_mm256_storeu_pd(sd, sum);
	sd[0] += sd[1];
	sd[2] += sd[3];
	sd[0] += sd[2];
	#pragma novector
	#pragma nounroll
	for (; i < n; i++) {
		sd[0] += v[i];
	}
	return sd[0];
}
