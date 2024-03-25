CFLAGS = -Wall -Wextra 
CC = gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

theme5 : theme6.o
	$(CC) $(CFLAGS) $^ -o theme6.out

clean:
	rm -rf *.o theme6.out
