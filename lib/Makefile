all: libbufio.so libhelpers.so

libbufio.so: bufio.c bufio.h
	gcc -o libbufio.so bufio.c -g -shared -Wall -I. -fpic

libhelpers.so: helpers.c helpers.h
	gcc -o libhelpers.so helpers.c -g -shared -Wall -I. -fpic

clean:
	rm -f *.o *.so
