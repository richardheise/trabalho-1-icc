#  @file  Makefile
#  @brief Arquivo de configuração do Make
#  @date 06/04/2022
#  @author Gabriel Lüders (GRR20190172)
#  @author Richard Fernando Heise Ferreira (GRR20191053) 

# ----------------------------------------------------------------- #
# Declaração das opções de compilação e alvos a serem compilados
CFLAGS = -Wall -g
CC = gcc
LIBS = -lm -lmatheval
OBJ = main.o newton.o mathLib.o utils.o methods.o
INPUT = fornecido/funcoes2.dat

# ----------------------------------------------------------------- #
# Declaração das diretrizes de compilação
all: newtonPC

newtonPC: $(OBJ)
	$(CC) -o newtonPC $(OBJ) $(LIBS)

run: all
	./newtonPC < $(INPUT)

valgrind: all
	valgrind ./newtonPC < $(INPUT)

valgrindFull: all
	valgrind --leak-check=full --show-leak-kinds=all  ./newtonPC < $(INPUT)

valgrindDoubleFree: all
	valgrind --track-origins=yes --keep-stacktraces=alloc-and-free --error-limit=no --num-callers=40 ./newtonPC < $(INPUT)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

newton.o: newton.c newton.h
	$(CC) -c newton.c $(CFLAGS)

mathLib.o: mathLib.c mathLib.h
	$(CC) -c mathLib.c $(CFLAGS)

utils.o: utils.c utils.h
	$(CC) -c utils.c $(CFLAGS)

methods.o: methods.c methods.h
	$(CC) -c methods.c $(CFLAGS)

# ----------------------------------------------------------------- #
# Diretrizes de limpeza
clean:
	$(RM) *.o

purge: clean
	$(RM) newtonPC