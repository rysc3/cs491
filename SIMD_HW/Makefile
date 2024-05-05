# This Makefile requires GNU make

CC = gcc
# Add -mavx2 to enable AVX instrusctions up to AVX2 as well as all SSE instructions.
# We use optimization level 1 to avoid automatic vectorization with both GCC
# and Clang. GCC will do automatic vectorization only at
# optimization level 3. Clang apparently will do it at level 2 or 3.

# -mtune=skylake encourages GCC to generate 256-bit vector instructions rather
# than sequences of two 128-bit vector instructions (which may be faster on
# some older processors)
CFLAGS = -g -O1 -std=c99 -mavx2 -mtune=skylake -Wall -fwrapv -fno-strict-aliasing
ASFLAGS = -g

DIST_FILES =  \
    add_benchmarks.c add_benchmark.h add_main.c \
    Makefile

all: add_benchmark regular sse \
     add_benchmarks.s 

add_benchmark: timing.o add_main.o add_benchmarks.o 
	$(CC) $(CFLAGS) -o $@ $^

add_benchmarks.s: add_benchmarks.c
	$(CC) $(CFLAGS) -g0 -S -o $@ $^

regular: regular_add.c
	$(CC) $(CFLAGS) -g0 -o regular_add $^

sse: sse_add.c 
	$(CC) $(CFLAGS) -g0 -o sse_add $^

clean:
	rm -f *.o sse_add regular_add add_benchmark
