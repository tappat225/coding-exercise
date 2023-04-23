
CC = gcc

FLAGS = -g -Wall -Wextra -pedantic -std=c99 -lcrypto -lssl

SRC = crl_test.c

TARGET = crlTest

build: ${SRC}
	${CC} ${SRC} -o ${TARGET} ${FLAGS}

.PHONY : clean

run: ${TARGET}
	./${TARGET}

clean:
	rm -rf ${TARGET} *.out certsDir
