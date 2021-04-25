#pragma once

struct cache_block
{
	uint64_t tag;
	char valid;
	char age;
//	char line[line_size];
};

int cache_access(struct cache_block *cache, unsigned int nsets,
	unsigned int associativity, unsigned int line_size, uint64_t address);

void cache_reset(struct cache_block *cache, unsigned int nsets,
	unsigned int associativity);

void age_update(int i, struct cache_block *cache, unsigned int set_index,
	unsigned int associativity);