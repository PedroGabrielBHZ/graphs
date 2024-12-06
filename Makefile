all: symetrique exploration_dilatation

symetrique: graphes.o symetrique.o
	gcc graphes.o symetrique.o -o symetrique

exploration_dilatation: graphes.o exploration_dilatation.o
	gcc graphes.o exploration_dilatation.o -o exploration_dilatation

graphes.o: graphes.c graphes.h
	gcc -c graphes.c

symetrique.o: symetrique.c graphes.h
	gcc -c symetrique.c

exploration_dilatation.o: exploration_dilatation.c graphes.h
	gcc -c exploration_dilatation.c

clean:
	rm -f *.o symetrique exploration_dilatation
