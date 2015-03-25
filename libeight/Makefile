all: example.b libeight.so

example.b: libeight.so example.o
	gcc -L. -o example.b example.o -leight

example.o: example.c
	gcc -c example.c

libeight.so: libeight.o
	gcc -shared -o libeight.so libeight.o

libeight.o: eight.c eight.h
	gcc -c -o libeight.o eight.c

clean:
	rm *.o *.b *.so
