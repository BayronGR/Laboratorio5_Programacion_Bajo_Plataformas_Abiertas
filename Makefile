CC=gcc
CFLAGS=-Wall
EX=lists

all: $(EX)

$(EX): main.o double_list.o
	$(CC) $(CFLAGS) -o $(EX) main.o double_list.o

main.o: main.c double_list.h
	$(CC) $(CFLAGS) -c main.c

double_list.o: double_list.c double_list.h
	$(CC) $(CFLAGS) -c double_list.c

valgrind: $(EX)
	valgrind --leak-check=full ./$(EX)

clean:
	rm -f *.o $(EX)
