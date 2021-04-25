CFLAGS += -I/apps/likwid/4.3.4/include -std=gnu99 -w2 -O3 -DLIKWID_PERFMON
LDLIBS += -L/apps/likwid/4.3.4/lib -lm -pthread -llikwid

ex04: ex04.c init_vec.c benchmark.c benchmark_nobranch.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: likwid assembly clean

likwid: ex04
	likwid-perfctr -C 1 -g BR_INST_RETIRED_ALL_BRANCHES:PMC0,\
	BR_MISP_RETIRED_ALL_BRANCHES:PMC1,BR_INST_RETIRED_NOT_TAKEN:PMC2 -m ./ex04

assembly: benchmark.c
	icc $(CFLAGS) -c -S -masm=intel $^ $(LDLIBS)

clean:
	rm -f ex04 benchmark.s