CC = gcc

flags = -std=c99 -fstack-protector-all -g -Wall -Werror

obj = main.o adt.o queue.o


bst-pointer-implementation: $(obj) bst.o
	$(CC) $(obj) bst.o -o bst-pointer-implementation -lm

main.o: main.c  
	$(CC) $(flags) -c main.c

bst.o: ./pointer-implementation/bst.c 
	$(CC) $(flags) -c ./pointer-implementation/bst.c

queue.o: ./queue/linked-list.c 
	$(CC) $(flags) -c ./queue/linked-list.c -o queue.o

adt.o: adt.c 
	$(CC) $(flags) -c adt.c
	
clean: 
	rm *.o bst-pointer-implementation
