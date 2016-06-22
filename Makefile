COMPILE = cc -std=c99 -pedantic -Wall -I /usr/local/include -I /usr/include -c
LINK = cc -L /usr/lib -L /usr/local/lib -l check

all: calculator check_roman_math

test: check_roman_math
	./check_roman_math

run: calculator
	./calculator

roman_math.o: roman_math.c include/roman_math.h
	${COMPILE} roman_math.c -o roman_math.o

check_roman_math.o: check_roman_math.c include/roman_math.h
	${COMPILE} check_roman_math.c 

calculator.o: calculator.c include/roman_math.h
	${COMPILE} calculator.c 

calculator: calculator.o roman_math.o
	${LINK} calculator.o roman_math.o -o calculator

check_roman_math: check_roman_math.o roman_math.o
	${LINK} check_roman_math.o roman_math.o -o check_roman_math

clean:
	rm -f *.o check_roman_math calculator
