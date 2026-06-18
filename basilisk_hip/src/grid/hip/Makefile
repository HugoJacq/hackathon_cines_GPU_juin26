# Standalone Makefile for HIP backend - do NOT include Makefile.defs
.PHONY: all clean
.SUFFIXES:

# ROCm paths - override if needed: make ROCM_PATH=/opt/rocm-7.2.0
ROCM_PATH ?= /opt/rocm

# Basilisk path
BASILISK ?= $(HOME)/basilisk/src

# AMD ROCm configuration (hardcoded for simplicity)
CC = hipcc
CFLAGS = -I$(BASILISK) -I$(ROCM_PATH)/include -I.. -DSINGLE_PRECISION -O2 -D__HIP_PLATFORM_AMD__

all: libhip.a

libhip.a: hip.o
	ar cr libhip.a hip.o

hip.o: hip.c ../gpu/backend.h
	$(CC) $(CFLAGS) -c hip.c -o hip.o

clean:
	rm -f *.o *.a
