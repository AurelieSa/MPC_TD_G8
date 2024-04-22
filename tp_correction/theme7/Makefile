CFLAGS = -Wall -Wextra
CC = gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

theme7 : theme7.c ./ififo/ififo_lib.h ./gfifo/gfifo_lib.h
	$(CC) $(CFLAGS) -o theme7.out theme7.c ./ififo/ififo_lib.c ./gfifo/gfifo_lib.c

clean:
	rm -rf *.o *.out

