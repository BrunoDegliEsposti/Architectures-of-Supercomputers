#include <stdio.h>
#include <stdlib.h>

double cache_access_doubles(double *v,
	size_t nelems, unsigned int line_size)
{
	double sum = 0.0; // we need to trick the compiler
	for (int i = 0; i < nelems; i += line_size/sizeof(double))
	{
		sum += v[i];
	}
	return sum;
}