all: fir

fir: fir.o main.o
	gcc -o fir fir.o main.o -lm

fir.o: fir.c
	gcc -o fir.o -c fir.c -W -Wall -ansi -pedantic -lm

main.o: main.c fir.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic -lm

clean:
	rm -rf *.o

mrproper: clean
	rm -rf fir
