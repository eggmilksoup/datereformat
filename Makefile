CC=cc
CFLAGS=-O2 -D_XOPEN_SOURCE
PREFIX=/usr/local

all: datereformat

install: all
	mkdir -p ${PREFIX}/bin
	cp datereformat ${PREFIX}/bin/

datereformat: datereformat.c
	${CC} ${CFLAGS} datereformat.c -o datereformat
