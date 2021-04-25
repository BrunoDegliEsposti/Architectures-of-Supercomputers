CFLAGS += -std=gnu99 -Wall -Os
LDLIBS += -lm

ex01: ex01.c init_buf.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: assembly upload clean

assembly: init_buf.c
	icc $(CFLAGS) -c -S -masm=intel $^ $(LDLIBS)
	less init_buf.s

upload:
	rsync -rzh --delete . hpcv178h@cshpc.rrze.fau.de:~/exercise01

clean:
	rm -f ex01 init_buf.s