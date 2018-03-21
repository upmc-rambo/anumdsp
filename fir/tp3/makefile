CC = gcc

rif: main.o change_to_binary.o mult.o fulladder.o
	$(CC) -o $@ $^

change_to_binary.o: change_to_binary.c
	gcc -o change_to_binary.o -c change_to_binary.c

mult.o: mult.c
	gcc -o mult.o -c mult.c

fulladder.o: fulladder.c
	gcc -o fulladder.o -c fulladder.c

main.o: main.c change_to_binary.h mult.h fulladder.h
	gcc -o main.o -c main.c

clean:
	rm -rf *.o
