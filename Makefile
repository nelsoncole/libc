CFLAGS=-Wall -m32 -ffreestanding -nostdlib -nostdinc -I ./include
.PHONY: all

all:
	gcc ${CFLAGS} -c *.c
#mov obj
	mv *.o obj
