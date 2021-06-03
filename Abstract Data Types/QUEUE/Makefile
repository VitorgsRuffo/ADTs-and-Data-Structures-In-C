CC = gcc

flags = -std=c99 -fstack-protector-all -g -Wall -Werror

obj = main.o adt.o 

all: queue-array-implementation queue-linked-list-implementation

queue-array-implementation: $(obj) array.o
	$(CC) $(obj) array.o -o queue-array-implementation -lm

queue-linked-list-implementation: $(obj) linked-list.o
	$(CC) $(obj) linked-list.o -o queue-linked-list-implementation -lm

main.o: main.c  
	$(CC) $(flags) -c main.c

array.o: ./array-implementation/array.c 
	$(CC) $(flags) -c ./array-implementation/array.c

linked-list.o: ./linked-list-implementation/linked-list.c 
	$(CC) $(flags) -c ./linked-list-implementation/linked-list.c

adt.o: adt.c 
	$(CC) $(flags) -c adt.c
	
clean: 
	rm *.o queue-array-implementation queue-linked-list-implementation
