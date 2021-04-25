CFLAGS += -std=gnu99 -w2 -O3 -xHost -qopt-streaming-stores always
LDLIBS += -lm -fopenmp

ex10: ex10.cu
	nvcc -arch sm_35 -O3 -o $@ $^

stream: stream.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: runcpu rungpu clean

runcpu:
	likwid-pin -q -c "E:N:20:1:2" ./stream

rungpu:
	./ex10
	#nvperf ./ex10
	#cuda-memcheck ./ex10

clean:
	rm -f stream ex10
