CFLAGS = -Wall -Wextra 
CC = gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

theme7 : theme7.o
	$(CC) $(CFLAGS) $^ -o theme7.out

clean:
	rm -rf *.o *.out
