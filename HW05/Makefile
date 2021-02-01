CC := gcc
#	Flags from class as a sys var
CFLAGS = -Wall -O3 -o

all: task1 task2

task1: task1.c
	#	Use dynamic patterns to compile
	$(CC) $< $(CFLAGS) $@

task2: mvmul.c task2.c
	#	Use static patterns to compile
	$(CC) mvmul.c task2.c $(CFLAGS) task2

clean:
	rm -f task1
	rm -f task2
