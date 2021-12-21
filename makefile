CC=gcc
AR=ar
FLAGS= -Wall -g
OBJECTS_MAIN=main.o
OBJECTS_STR=functions.o

all: stringProg

stringProg: $(OBJECTS_MAIN) $(OBJECTS_STR)
	$(CC) $(FLAGS) $(OBJECTS_MAIN) $(OBJECTS_STR) -o stringProg
	
main.o: main.c functions.h
	$(CC) $(FLAGS) -c main.c
	
StringFunctions.o: functions.c functions.h
	$(CC) $(FLAGS) -c functions.c


.PHONY: clean
.PHONY: all



clean:
	rm -f *.o stringProg
