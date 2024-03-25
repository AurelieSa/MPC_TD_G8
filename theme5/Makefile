CFLAGS = -Wall -Wextra 
CC = gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

theme5 : theme5.o
	$(CC) $(CFLAGS) $^ -o theme5.out

clean:
	rm -rf *.o theme5.out
