all: big.o fancy.o calculator.o
	gcc big.o fancy.o calculator.o -o big-sqrt

big.o: big.h big.c
	gcc --std=c99 big.c -O3 -c -o big.o

fancy.o: fancy.h fancy.c
	gcc --std=c99 fancy.c -O3 -c -o fancy.o

calculator.o: fancy.h big.h calculator.c
	gcc --std=c99 calculator.c -O3 -c -o calculator.o

clean:
	rm *.o
