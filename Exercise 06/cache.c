#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "cache.h"

int cache_access(struct cache_block *cache, unsigned int nsets,
	unsigned int associativity, unsigned int line_size, uint64_t address)
{
	unsigned int line_index = address & (line_size-1);
	address /= line_size;
	unsigned int set_index = address & (nsets-1);
	address /= nsets;
	uint64_t tag = address;

	// HIT?
	for (int i = 0; i < associativity; i++) {
		ptrdiff_t block_index = set_index * associativity + i;
		struct cache_block *b = cache + block_index;
		if (tag == b->tag && b->valid) {
			age_update(i,cache,set_index,associativity);
			return 1;
		}
	}

	// HANDLE CACHE MISS
	for (int i = 0; i < associativity; i++) {
		ptrdiff_t block_index = set_index * associativity + i;
		struct cache_block *b = cache + block_index;
		if (b->age == associativity-1) {
			b->tag = tag;
			b->valid = 1;
			age_update(i,cache,set_index,associativity);
			return 0;
		}
	}

	fprintf(stderr, "LRU error\n");
	exit(EXIT_FAILURE);
}

void cache_reset(struct cache_block *cache, unsigned int nsets,
	unsigned int associativity)
{
	unsigned int nblocks = nsets*associativity;
	for (int i = 0; i < nblocks; i++) {
		cache[i].valid = 0;
		cache[i].age = i % associativity;
	}
}

void age_update(int i, struct cache_block *cache, unsigned int set_index,
	unsigned int associativity)
{
	char age_to_update = cache[set_index*associativity+i].age;
	for (int j = 0; j < associativity; j++) {
		ptrdiff_t block_index = set_index * associativity + j;
		struct cache_block *b = cache + block_index;
		if (b->age < age_to_update) {
			b->age++;
		} else if (b->age == age_to_update) {
			b->age = 0;
		}
	}
}