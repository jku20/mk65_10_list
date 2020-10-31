CC = gcc
OBJECTS = animation.o main.o

all: main

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

$(OBJECTS): animation.h

animation.o: animation.c
main.o: main.c

.PHONY: run clean

run: 
	./main

clean:
	rm *.o
