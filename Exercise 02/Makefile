CFLAGS += -std=gnu99 -Wall -Os
LDLIBS += -lm

ex02: ex02.c init_vec.c sum_vec*.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: assembly upload clean

assembly: sum_vec2.c
	icc $(CFLAGS) -c -S -masm=intel $^ $(LDLIBS)
	less sum_vec2.s

clean:
	rm -f ex02 sum_vec2.s
