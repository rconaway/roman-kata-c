CC = cc
CFLAGS = -std=c99 -pedantic -Wall

all: calculator check_roman_math

test: check_roman_math
	./check_roman_math

roman_math.o: roman_math.c include/roman_math.h
	$(CC) $(CFLAGS) -c roman_math.c

check_roman_math.o: check_roman_math.c include/roman_math.h
	$(CC) $(CFLAGS) -c check_roman_math.c

calculator.o: calculator.c include/roman_math.h
	$(CC) $(CFLAGS) -c calculator.c

calculator: calculator.o roman_math.o
	$(CC) calculator.o roman_math.o -L /usr/lib -L /usr/local/lib -o calculator

check_roman_math: check_roman_math.o roman_math.o
	$(CC) check_roman_math.o roman_math.o -L /usr/lib -L /usr/local/lib -o check_roman_math

clean:
	rm -f *.o check_roman_math calculator
