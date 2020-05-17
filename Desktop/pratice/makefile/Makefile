OBJS=f1.o f2.o main.o
CC=gcc
CFLAGS=-Wall -O -g
test:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
f1.o:f1.c
	$(CC) -c $^ -o f1.o
f2.o:f2.c
	$(CC) -c $< -o f2.o
main.o:main.c
	gcc -c main.c -o main.o
clean:
	rm *.o test
