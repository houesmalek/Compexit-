#ifndef UTILS__H
#define UTILS__H
#include "../headers/graph.h"



/*********** MANIP LISTE **********/
void ajoute_arete(chain_list * c, Sommet s);

void ajoute_arete_liste(graph * g, Sommet s1, Sommet s2);

/*********** MANIP MATRICE **********/
void init_matrice (graph *g);

void ajoute_arete_matrice(graph  *g, Sommet s1, Sommet s2);

void alloc_mat(graph *g, int nbs);


/*********** LECTURE **********/
void lecture_fgraph(char * nomfic, graph *g);

void lecture_fse(FILE * fs, graph * g, int * tab);

#endif
