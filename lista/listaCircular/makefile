# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -std=c90 -g  # flags de compilacao
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
	objects = main.o liblista.o 
     
all: main.o liblista.o
	$(CC) -o main main.o liblista.o $(LDFLAGS)

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

liblista.o: liblista.c
	$(CC) -c $(CFLAGS) liblista.c

clean:
	rm -f $(objects) main
