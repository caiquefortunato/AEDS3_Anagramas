lista: lista.o main.o
	gcc lista.o main.o -o lista
main.o: main.c lista.h
	gcc -g -c main.c
lista.o: lista.h lista.c
	gcc -g -c lista.c
clean:
	rm *.o *.gch
	rm lista
