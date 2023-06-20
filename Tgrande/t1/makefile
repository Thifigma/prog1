#Esse makefile deve gerar um executavel agenda 
#para executar o teste 'firma'.

CC = gcc
CFLAGS = -Wall -std=c99 -g
LDFLAGS = -lm

all: agenda

agenda: agenda.o libagenda.o
	$(CC) $(LDFLAGS) -o agenda agenda.o libagenda.o

agenda.o: agenda.c libagenda.h
	$(CC) $(CFLAGS) -c agenda.c

libagenda.o: libagenda.c libagenda.h
	$(CC) $(CFLAGS) -c libagenda.c

clean:
	rm -f agenda.o libagenda.o agenda