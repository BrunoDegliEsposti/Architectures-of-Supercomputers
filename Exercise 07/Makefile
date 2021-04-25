CFLAGS += -I/apps/likwid/4.3.4/include -std=gnu99 -w2 -O3 -DLIKWID_PERFMON
LDLIBS += -L/apps/likwid/4.3.4/lib -lm -pthread -llikwid

ex07: ex07.c cache_access.c
	icc $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: likwid assembly clean

likwid: ex07
	nbytes=$$((30*1024)) ; while [[ $$number -le $$((40*1024)) ]] ; do \
		echo $$nbytes ; \
        likwid-perfctr -C 1 -g MEM_UOPS_RETIRED_LOADS:PMC0,\
	MEM_LOAD_UOPS_RETIRED_L1_HIT:PMC1 -m ./ex07 $$nbytes | grep UOPS; \
		echo ; \
        ((nbytes = nbytes + 512)) ; \
    done

assembly: cache_access.c
	icc $(CFLAGS) -c -S -masm=intel $^ $(LDLIBS)

clean:
	rm -f ex07