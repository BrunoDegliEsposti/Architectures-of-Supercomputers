#include <stdio.h>
#include <stdlib.h>

double benchmark(int *v, size_t len) {
	double result = 0;
	for (size_t i = 0; i < len; i++) {
		if (v[i] == 0) {
			result += 1.0;
		} else {
			result -= 1.0;
		}
	}
	return result;
}
