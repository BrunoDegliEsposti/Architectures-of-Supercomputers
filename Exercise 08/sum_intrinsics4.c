#include <stdio.h>
#include <stdlib.h>
#include "x86intrin.h"

double sum_intrinsics4(double const *v, size_t n) {
	__m256d sum0 = _mm256_setzero_pd();
	__m256d sum1 = _mm256_setzero_pd();
	__m256d sum2 = _mm256_setzero_pd();
	__m256d sum3 = _mm256_setzero_pd();
	__m256d pd0, pd1, pd2, pd3;
	double sd[4];
	size_t i;
	size_t nrounded = n - (n%16);
	#pragma novector
	#pragma nounroll
	for (i = 0; i < nrounded; i+=16) {
		pd0 = _mm256_load_pd(&v[i]);
		pd1 = _mm256_load_pd(&v[i+4]);
		pd2 = _mm256_load_pd(&v[i+8]);
		pd3 = _mm256_load_pd(&v[i+12]);
		sum0 = _mm256_add_pd(sum0, pd0);
		sum1 = _mm256_add_pd(sum1, pd1);
		sum2 = _mm256_add_pd(sum2, pd2);
		sum3 = _mm256_add_pd(sum3, pd3);
	}
	sum0 = _mm256_add_pd(sum0, sum1);
	sum2 = _mm256_add_pd(sum2, sum3);
	sum0 = _mm256_add_pd(sum0, sum2);
	sum0 = _mm256_hadd_pd(sum0, sum0);
	pd0 = _mm256_castpd128_pd256(_mm256_extractf128_pd(sum0, 1));
	sum0 = _mm256_add_pd(sum0, pd0);
	if (i < n) {
		_mm256_storeu_pd(sd, sum0);
		#pragma novector
		#pragma nounroll
		for (; i < n; i++) {
			sd[0] += v[i];
		}
		return sd[0];
	} else {
		_mm256_storeu_pd(sd, sum0);
		return sd[0];
	}
}
