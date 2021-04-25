CFLAGS += -std=gnu99 -w2 -O3 -xHost
LDLIBS += -lm -pthread

ex08: ex08.c init_vec.c sum_intrinsics1.c sum_intrinsics4.c sum_auto.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: likwid clean

assembly: sum_intrinsics4.c
	icc $(CFLAGS) -c -S -masm=intel $^ $(LDLIBS)

clean:
	rm -f ex08 *.optrpt *.s