CFLAGS = -Wall -Wextra 
CC = gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

theme6 : theme6.o
	$(CC) $(CFLAGS) $^ -o theme6.out

clean:
	rm -rf *.o *.out
