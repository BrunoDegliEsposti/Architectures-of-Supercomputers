#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_vec(int *v, size_t len) {
	srandom(time(NULL));
	for (size_t i = 0; i < len; i++) {
		v[i] = random() % 2;
	}
}
