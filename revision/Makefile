CFLAGS = -Wall -Wextra 
CC = gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

rev : rev.o
	$(CC) $(CFLAGS) $^ -o rev.out

clean:
	rm -rf *.o *.out
