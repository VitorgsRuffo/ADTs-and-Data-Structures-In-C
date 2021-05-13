CC = gcc

flags = -std=c99 -fstack-protector-all -g -Wall #-Werror

obj = main.o linked-list.o adt.o 


program: $(obj)
	$(CC) $(obj) -o program -lm

main.o: main.c  
	$(CC) $(flags) -c main.c

linked-list.o: linked-list.c 
	$(CC) $(flags) -c linked-list.c

adt.o: adt.c 
	$(CC) $(flags) -c adt.c
	
clean: 
	rm $(obj) program