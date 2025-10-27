default: build_poc build_test

build_poc: poc.o
	cc poc.o -o poc -pthread

build_test: test.o
	cc test.o -o test -pthread

poc.o: poc.c proj3KernelTemplate.h
	cc -c -g poc.c -o poc.o

test.o: test.c proj3KernelTemplate.h
	cc -c -g test.c -o test.o

proj3KernelTemplate.h: 421proj3structs.h
	# do nothing

421proj3structs.h:
	# do nothing

clean:
	rm -f *.o poc test

