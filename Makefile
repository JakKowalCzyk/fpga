all : libshared f 

libshared : libshared
	gcc -c shared.c -o libshared.so 

shared.o : shared.c
	gcc -c shared.c

f : f.o
	gcc -o f libshared.so f.o

f.o : f.c
	gcc -c f.c

clean :
	rm *.o *.so

