#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cache.h"

int is_power_of_2(unsigned int n) {
	return n && !(n & (n-1));
}

int main(int argc, char **argv) {
	/* ===== INPUT PARSING ===== */
	if (argc != 6) {
		fprintf(stderr, "Usage: %s cache_size nsets associativity "
			"line_size array_size\n", argv[0]);
		return 1;
	}
	unsigned int cache_size, nsets, associativity;
	unsigned int line_size, array_size;
	sscanf(argv[1], "%u", &cache_size);
	sscanf(argv[2], "%u", &nsets);
	sscanf(argv[3], "%u", &associativity);
	sscanf(argv[4], "%u", &line_size);
	sscanf(argv[5], "%u", &array_size);
	if (cache_size != nsets * associativity * line_size) {
		fprintf(stderr, "Error: inconsistent input data\n");
		return 1;
	}
	if (!is_power_of_2(nsets)) {
		fprintf(stderr, "Error: the number of cache sets must be a power of 2\n");
		return 1;
	}
	if (!is_power_of_2(associativity)) {
		fprintf(stderr, "Error: the associativity of the cache must be a power of 2\n");
		return 1;
	}
	if (!is_power_of_2(line_size)) {
		fprintf(stderr, "Error: the size of a cache line must be a power of 2\n");
		return 1;
	}

	/* ===== INITIALIZATION ===== */
	unsigned int nblocks = nsets*associativity;
	struct cache_block *cache = malloc(nblocks*sizeof(struct cache_block));
	cache_reset(cache, nsets, associativity);

	/* ===== ARRAY TRAVERSALS ===== */
	uint64_t array_start = 0xC0FFEE;
	for (int i = 0; i < array_size; i += line_size) {
		cache_access(cache, nsets, associativity, line_size, array_start+i);
	}
	unsigned int accesses = 0;
	unsigned int hits = 0;
	for (int i = 0; i < array_size; i += line_size) {
		accesses += 1;
		hits += cache_access(cache, nsets, associativity, line_size, array_start+i);
	}
	float hit_ratio = (float)hits/accesses;
	printf("Hit ratio: %f\n", hit_ratio*100);
	return 0;
}
