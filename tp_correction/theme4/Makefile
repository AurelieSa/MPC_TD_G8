CFLAGS = -Wall -Wextra
CC = gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

theme4 : theme4.o
	$(CC) $(CFLAGS) $^ -o theme4.out

clean:
	rm -rf *.o *.out

