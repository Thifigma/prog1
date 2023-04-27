cc = gcc
cFLAGS= -Wall 

main: main.o libConfeitaria.o
	$(cc) main.o libConfeitaria.o -o main $(cFLAGS)

main.o: main.c 
	$(cc) $(cFLAGS) -c main.c 

libConfeitaria.o: libConfeitaria.c
	$(cc) $(cFLAGS) -c libConfeitaria.c

clean: 
	rm *.o main
