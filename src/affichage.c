#include <stdio.h>
#include <stdlib.h>
#include "../headers/graph.h"

void affiche_liste(graph * g){
	chain_list c;
	for(int i=0;i<g->nb_sommets;i++){
		c=g->list_voisins[i];
		printf("sommet %d : ", i);
		while(c!=NULL){
			printf("%d ",c->info);
			c=c->suiv;
			
		}
		printf("\n\n");

	}
}

void affiche_sommets(Sommet * tab, Sommet nbs)
{
	for(int i=0;i<nbs;i++)
	{
		printf("test");		
		printf("%d", tab[i]);
		printf("\n\n");

	}
}


void affiche_matrice(graph *g)
{
int i;
	printf("\t");
	for (i=0; i<g->nb_sommets; i++)
		printf("%d\t", i);
		
	printf("\n");
	

	//printf(" nb_sommets= %d  ",g->nb_sommets);
	for (i=0; i<g->nb_sommets; i++)
	{
		printf("%d\t",i);
			for (int j=0; j<g->nb_sommets; j++)
		{
				//printf("%d ",j);
				printf("%d\t",g->mat_voisins[i][j] );


		}	

		printf("\n");
	}
}