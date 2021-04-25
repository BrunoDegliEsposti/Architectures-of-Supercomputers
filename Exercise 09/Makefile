CFLAGS += -std=gnu99 -w2 -O3 -xHost
LDLIBS += -lm -fopenmp

ex09: ex09.c sum_auto.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: assembly upload clean

assembly: sum_auto.c
	icc $(CFLAGS) -c -S -masm=intel $^ $(LDLIBS)
	less sum_auto.s

clean:
	rm -f ex09 sum_auto.s
