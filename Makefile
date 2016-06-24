COMPILE = cc -std=c99 -pedantic -Wall -I /usr/local/include -I /usr/include -c
LINK = cc -L /usr/lib -L /usr/local/lib -l check

all: calculator check_to_arabic

test: check_to_arabic check_to_roman check_roman_math
	./check_to_arabic
	./check_to_roman
	./check_roman_math

run: calculator
	./calculator

to_arabic.o: to_arabic.c include/to_arabic.h
	${COMPILE} to_arabic.c -o to_arabic.o

check_to_arabic.o: check_to_arabic.c include/to_arabic.h
	${COMPILE} check_to_arabic.c 

check_to_arabic: check_to_arabic.o to_arabic.o
	${LINK} check_to_arabic.o to_arabic.o -o check_to_arabic

to_roman.o: to_roman.c include/to_roman.h
	${COMPILE} to_roman.c -o to_roman.o

check_to_roman.o: check_to_roman.c include/to_roman.h
	${COMPILE} check_to_roman.c 

check_to_roman: check_to_roman.o to_roman.o
	${LINK} check_to_roman.o to_roman.o -o check_to_roman

roman_math.o: roman_math.c include/roman_math.h
	${COMPILE} roman_math.c -o roman_math.o

check_roman_math.o: check_roman_math.c include/roman_math.h
	${COMPILE} check_roman_math.c 

check_roman_math: check_roman_math.o roman_math.o
	${LINK} check_roman_math.o roman_math.o -o check_roman_math

calculator.o: calculator.c include/to_arabic.h
	${COMPILE} calculator.c 

calculator: calculator.o to_arabic.o
	${LINK} calculator.o to_arabic.o -o calculator

clean:
	rm -f *.o check_to_arabic calculator
