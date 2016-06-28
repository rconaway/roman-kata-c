CC=gcc
CFLAGS=-Wall -std=gnu99
LDLIBS=-pthread -lcheck_pic -lrt -lm

all: clean check_to_arabic check_to_roman check_roman_math calculator test

test: 
	./check_to_arabic
	./check_to_roman
	./check_roman_math

check_to_arabic: 
	${CC} ${CFLAGS} check_to_arabic.c to_arabic.c -o check_to_arabic ${LDLIBS}

check_to_roman:  
	${CC} ${CFLAGS} check_to_roman.c to_roman.c -o check_to_roman ${LDLIBS}

check_roman_math:  
	${CC} ${CFLAGS} check_roman_math.c roman_math.c to_roman.c to_arabic.c -o check_roman_math ${LDLIBS}

calculator:  
	${CC} ${CFLAGS} calculator.c to_roman.c to_arabic.c roman_math.c -o calculator ${LDLIBS}

clean:
	rm -f *.o check_to_arabic check_to_roman check_roman_math calculator
