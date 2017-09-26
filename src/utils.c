#include <stdio.h>
#include <stdlib.h>
#include "../headers/graph.h"
#include "../headers/affichage.h"


/*********** MANIP LISTE **********/
void ajoute_arete(chain_list * c, Sommet s){
	chain_list p;
	p = (chain_list) malloc (sizeof(maillon));
	p->info = s;
	p->suiv = *c;
	*c = p;
}

void ajoute_arete_liste(graph * g, Sommet s1, Sommet s2){
	ajoute_arete(&g->list_voisins[s1], s2);
	ajoute_arete(&g->list_voisins[s2], s1);
}


/*********** MANIP MATRICE **********/

void init_matrice (graph *g)
{
	for (int i=0; i<g->nb_sommets; i++)
		for (int j=0; j<g->nb_sommets; j++)
			g->mat_voisins[i][j]=0;

}

void ajoute_arete_matrice(graph  *g, Sommet s1, Sommet s2)
{

	g->mat_voisins[s1][s2]=1;
	g->mat_voisins[s2][s1]=1;

}



void alloc_mat(graph *g, int nbs)
{
  	g->mat_voisins = (int**) malloc (nbs *sizeof(int*));
  	if (g->mat_voisins == NULL)
  	{
  		fprintf(stderr, "Allocation Impossible");
		exit(EXIT_FAILURE);
  	}
  	for (int x=0; x<nbs; x++)
  	{
  		g->mat_voisins[x]=(int *) malloc (nbs *sizeof(int)); //PROB
  		if (g->mat_voisins[x] == NULL)
  		{
  			fprintf(stderr, "Allocation Impossible");
			exit(EXIT_FAILURE);

  		}
  		
  		
	}
	printf("done\n");
}



/*********** LECTURE **********/

void lecture_fgraph(char * nomfic, graph * g){
	FILE *f;
	Sommet nbs, s1, s2;
	Aretes nba;
	int i;

	f = fopen(nomfic, "r");

	fscanf(f, "%d %d", &nbs, &nba);
	printf("Graphe : %d sommets, %d aretes\n", nbs, nba);

	g->nb_sommets = nbs;
	g->list_voisins = (chain_list *) malloc (sizeof(chain_list) * nbs);

	alloc_mat(g, nbs);
	init_matrice(g);

	for(i=0; i < nba ; i++)
	{
		if(feof(f) != 0)
		{
			printf("Erreur fichier mal formé. Pas assez d'aretes.\n");
			exit(EXIT_FAILURE);
		}
		fscanf(f, "%d %d", &s1, &s2);
		ajoute_arete_liste(g, s1, s2);
		ajoute_arete_matrice(g,s1,s2);
		
	}
	
	fclose(f);
}

void lecture_fse(FILE * fs, graph * g, int * tab){
	Sommet nbse, sse;
	int i;
	
	fscanf(fs, "%d", &nbse);
	if(nbse > g->nb_sommets)
	{
		printf("Erreur trop de sommets\n");
		exit(EXIT_FAILURE);
	}
		
	for(i=0; i < nbse; i++)
	{
		fscanf(fs, "%d", &sse);
		tab[sse] = 1;
	}
		
	affiche_sommets(tab, nbse);
}
