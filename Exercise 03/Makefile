CFLAGS += -std=gnu99 -w3 -O3
LDLIBS += -lm

ex03: ex03.c init_vec.c benchmark.c benchmark_nobranch.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: assembly upload clean

assembly: benchmark_nobranch.c
	icc $(CFLAGS) -c -S -masm=intel $^ $(LDLIBS)
	less benchmark_nobranch.s

clean:
	rm -f ex03 benchmark_nobranch.s