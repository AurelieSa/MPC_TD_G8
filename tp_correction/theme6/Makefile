CFLAGS = -Wall -Wextra
CC = gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

theme6 : theme6.o
	$(CC) $(CFLAGS) $^ -o theme6.out


ga : main_ga.c ./tableaux_grandissant/libga.h
	$(CC) $(FLAGS) -o ga.out main_ga.c ./tableaux_grandissant/libga.c

clean:
	rm -rf *.o *.out

