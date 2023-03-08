CC = gcc
CFLAGS = -Wall -std=c11

all: main.elf

main.elf: main.c
	$(CC) $(CFLAGS) main.c -o main.elf
	$(CC) $(CFLAGS) HW01.c -o HW01.elf
clean:
	rm -f *.o *.elf
