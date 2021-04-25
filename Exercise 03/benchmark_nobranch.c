#include <stdio.h>
#include <stdlib.h>

double benchmark_nobranch(int *v, size_t len) {
	double result = 0;
	for (size_t i = 0; i < len; i++) {
		result += 1.0;
	}
	return result;
}
