#!/usr/bin/env bash

for size in {27,120,1024,204800}; do
	echo "Workload per thread: $size KB"
	for n in {1..10}; do
		#likwid-pin -q -c "E:N:$n:1:2" ./ex09 $((n * size * 1024))
		likwid-pin -q -c "E:N:$((2*n)):2:2" ./ex09 $((n * size * 1024))
	done
	echo
done
