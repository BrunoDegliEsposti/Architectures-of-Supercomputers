#include <stdio.h>
#include <stdlib.h>

void init_buf(double *buf, size_t len) {
	#pragma novector
	for (size_t i = 0; i < len; i++) {
		buf[i] = 1.0;
	}
}
