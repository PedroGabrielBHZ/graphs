#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "graphes.h"

/* ci-dessous trois macros pour pouvoir utiliser les termes, booleens, VRAI et FAUX dans les programmes */
#define booleen unsigned char
#define VRAI 1
#define FAUX 0

/*
 retourne le dilate D de l'ensemble E dans le graphe G                   
 les ensembles E et D sont représentés par des tableaux booleens         
 la mémoire pour E est supposée allouée avec autant de case            
 que de sommets dans G                                                 
 la mémoire pour D est allouée a l'intérieur de la fonction            
*/
booleen * dilatation(graphe* G, booleen *E){
    booleen *D;   // tableau boolen pour stocker le résultat de la dilatation
    int x;        // pour parcourir les sommets de G
    pcell p;      // pointeur vers maillon pour parcourir des listes de successeurs

    /* comme D est un sous ensemble des sommets de G on a besoin
    d'autant de cases que de sommets de G */
    D = (booleen *) calloc(G->nsom, sizeof(booleen));

    // Parcourt tous les sommets de G
    for (x = 0; x < G->nsom; x++) {
        if (E[x]) { // Vérifie si x appartient à E
            for (p = G->gamma[x]; p != NULL; p = p->suivant) { // Parcourt les successeurs de x
                D[p->som] = 1;  // Ajoute y à D (y est le sommet correspondant à p->som) */
            }
        }
    }

    return D; // Renvoie le tableau booléen D
}


/* ====================================================================== */
int main(int argc, char **argv)
/* ====================================================================== */
{
  graphe *G;
  int nd;           // nombre d'etapes de dilatation
  int x;            // sommet de depart à explorer
  booleen *E, *D;   // tableau pour stocker les ensembles successifs et leurs dilates
  int i;            // indice muet
  
  if (argc != 4)
  {
    fprintf(stderr, "usage: %s <donnee.graphe> <sommet_initial_a_explorer> <nb_dilatation>\n", argv[0]);
    fprintf(stderr, "            ou %s explore le graphe donnee.grahe en faisant nb_dilatation etapes de dilatation a partir de l'ensemble contenant sommet_initial_a_explorer\n", argv[0]);
    exit(0);
  }

  /**********************************************************/
  /* Lecture des arguments passes au programmme             */
  /**********************************************************/
  
  G = litGraphe(argv[1]);       // Lit un graphe stockée dans un fichier
  
  x = atoi(argv[2]);

  if(x >= G->nsom){
    fprintf(stderr, "Erreur: pas de sommet d'indice %d dans %s\n", x, argv[1]);
    exit(0);
  }

  nd = atoi(argv[3]);

  if(nd < 0){
    fprintf(stderr, "Erreur : le nombre d'etapes d'exploration doit etre positif.\n");
    exit(0);
  }


  /**********************************************************/
  /* Debut de l'exploration                                 */
  /**********************************************************/
  printf("Exploration (%d étapes de dilatation) du graphe %s a partir du sommet %d\n\n\n", nd, argv[1],x);

  
  /* initialisation de l'ensemble E : E := {x}*/
  E = (booleen*) calloc(G->nsom, sizeof(booleen));
  E[x] = VRAI;

  for(i = 0 ; i < nd; i++){
    D = dilatation(G,E);
    
    /* On affiche le résultat */
    printf("**********************\n");
    printf("Étape %d\n",i);
    printf("**********************\n");
    printf("D_%d  contient les sommets", i);
    for(x = 0; x < G->nsom; x++)
      if(D[x] == VRAI)
	printf(" %d", x);
    printf(".\n");
    
    /* si un nom est diponible pour les sommets, on affiche aussi les noms */
    if( (G->info != NULL) && G->info[0].nom != NULL){
      printf("--\nDont les noms sont :\n");
      for(x = 0; x < G->nsom; x++)
	if(D[x] == VRAI)
	  printf("%s\n", G->info[x].nom);
    }

    /* A l'etape suivante il faudra explorer les sommets de D */
    free(E);
    E = D;
  }

  free(D);
  return 0;
} /* main() */

