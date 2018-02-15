# symb

CC = gcc
CFLAGS = -Wall

SRC = symb.c

symb:
	${CC} ${CFLAGS} ${SRC} -o $@

clean:
	rm -f *.o symb
