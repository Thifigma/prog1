#Diretiva de compilacao
FLAGS = -Wall -Werror -Wextra -pedantic

#Define uma variavel para dar nome ao programa
 
nomeProg = tp1

all: $(nomeProg)	#Define que o arquivo de nomeProg vai receber todos os comandos abaixo.


#Vai renomear os arquivos objetos que serão gerados pelo programa e vai aplicar as  diretivas
#Os objetos é resultado da compilacao do programa principal.
$(nomeProg): main.o libAgenda.o
		gcc -o $(nomeProg) main.o libAgenda.o $(FLAGS)
  
libAgenda.o: libAgenda.h libAgenda.c
	gcc -c libAgenda.c $(FLAGS)

#Limpa os arquivos objeto

clean:
	rm -f*.o*.gch $(nomeProg)
