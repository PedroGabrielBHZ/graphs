/* strcture pour m�moriser les informations additionelles des sommets */

typedef struct {
  //!  nom du sommet
  char *nom; 
  //!  abcisse du sommet 
  double x;        
  //!  ordonnee du sommet
  double y;        
  //!  altitude du sommet
  double alt;        
  //!  tableau de poids associ�es aux sommets
  double poids;
} sInfo;


/* structure de maillon pour les listes cha�nees de successeurs. */
typedef struct cell {
//! index du sommet
  int som;
//! suite de la liste ou pointeur NULL
  struct cell * suivant; 
} cell;

/*! \var pcell
    \brief pointeur sur une cellule
*/
typedef cell * pcell; 


/* structure pour la representation des graphes */
typedef struct graphe {

  /* informations globales */
//!  nombre de sommets 
  int nsom;          
//!  nombre d'arcs
  int narc;
//!  tableau des informations aditionnelles pour les sommets
  sInfo * info;
//!  tableau des listes de successeurs index� par les sommets 
  pcell * gamma;    

  /* Champs additionnels utilis�s pour g�rer efficacement et
     dynamiquement la m�moire des graphes. */
  /* Il n'est pas n�cessaire de s'y int�resser dans le cadre du cours
     graphes et algorithmes */
  //!  nombre maximum d'arcs
  int nmaxarc;
  //!  tableau des cellules en r�serve 
  pcell reserve;    
  //!  liste des cellules libres g�r�e en pile lifo 
  pcell libre;      
} graphe;


/* ====================================================================== */
/* ====================================================================== */
/* FONCTIONS D'ALLOCATION / LIBERATION POUR UN GRAPHE */
/* ====================================================================== */
/* ====================================================================== */

extern graphe * initGraphe(int nsom, int nmaxarc);
extern void termineGraphe(graphe * g);

/* ====================================================================== */
/* ====================================================================== */
/* FONCTIONS DE lECTURE ET DE SAUVEGARDE EN FICHIER  */
/* ====================================================================== */
/* ====================================================================== */

extern graphe * litGraphe(char * filename);
extern void sauvegardeGraphe(graphe * g, char *filename, int opt);
extern void cpyInfo(graphe *g1, graphe *g2);

/* ====================================================================== */
/* ====================================================================== */
/* FONCTIONS DE MANIPULATION DES ARCS */
/* ====================================================================== */
/* ====================================================================== */

extern void ajouteSuccesseur(graphe * g, int i, int s);
