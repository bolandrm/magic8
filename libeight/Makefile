all: example.b

example.b: example.o libeight.o
	gcc -o example.b libeight.o example.o

example.o: example.c
	gcc -c example.c

libeight.o: eight.c eight.h
	gcc -c -o libeight.o eight.c

clean:
	rm *.o *.b
