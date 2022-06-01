CC = gcc
FLAG = -g -Wall

OBJS = client.o server.o

all:server client

client: client.o
	$(CC) $(FLAG) client.o -o client

server: server.o
	$(CC) $(FLAG) server.o -o server

client.o:client.c
server.o:server.c

.PHONY:clean
clean:
	-rm client server $(OBJS)
