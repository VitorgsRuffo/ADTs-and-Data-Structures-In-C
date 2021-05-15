CC = gcc

flags = -std=c99 -fstack-protector-all -g -Wall -Werror

obj = main.o adt.o

list-linked-list-implementation: $(obj) linked-list.o
	$(CC) $(obj) linked-list.o -o list-linked-list-implementation -lm


main.o: main.c  
	$(CC) $(flags) -c main.c

linked-list.o: ./linked-list-implementation/linked-list.c 
	$(CC) $(flags) -c ./linked-list-implementation/linked-list.c

adt.o: adt.c 
	$(CC) $(flags) -c adt.c
	
clean: 
	rm *.o list-linked-list-implementation