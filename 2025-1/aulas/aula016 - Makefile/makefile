
all: teste

teste: aluno.o main.o
	gcc -o teste aluno.o main.o

aluno.o: aluno.c aluno.h
	gcc -c aluno.c -Wall -Werror -Wextra

main.o: main.c aluno.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o teste