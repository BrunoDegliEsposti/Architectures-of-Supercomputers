CFLAGS += -std=gnu99 -Wall -Os
LDLIBS += -lm

ex05: ex05.c init_vec.c mul_vec*.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: assembly upload clean

assembly: mul_vec1.c
	icc $(CFLAGS) -c -S -masm=intel $^ $(LDLIBS)
	less mul_vec1.s

clean:
	rm -f ex05 mul_vec1.s
