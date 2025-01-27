all: laff

laff: include/constants/global.h include/queuetype.h include/main.h src/main.c
	gcc -o laff -g -Iinclude src/main.c

clean:
	rm -f laff *.o
