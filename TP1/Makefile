all: 	symetrique

symetrique:	graphes.o symetrique.o
	gcc graphes.o symetrique.o -o symetrique

graphes.o: 	graphes.c graphes.h
	gcc -c graphes.c

symetric.o:	symetrique.c graphes.h
	gcc -c symetrique.c
