main.o: main.c
	gcc -c main.c
module.o: module.c module.h
	gcc -c module.c
all: module.o main.o
	gcc module.o main.o -o all
run: all
	./all
clean: main.o module.o
	rm -rf *.o