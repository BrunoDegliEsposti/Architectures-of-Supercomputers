CFLAGS += -std=gnu99 -Wall -O2
LDLIBS += -lm

ex06: ex06.c cache.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

graph: graph.c cache.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean

clean:
	rm -f ex06 graph
