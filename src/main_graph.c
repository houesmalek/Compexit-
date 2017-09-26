#include <stdio.h>
#include <stdlib.h>
#include "../headers/graph.h"
#include "../headers/affichage.h"
#include "../headers/utils.h"


/*void lecture (char [] , graph * g)*/


int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Usage : %s <fichier_graphe> <fichier_sommets>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	graph g;
	FILE * fs;
	int tab[g.nb_sommets]; 
	
	lecture_fgraph(argv[1], &g);
	
	fs = fopen(argv[2], "r");
	while(feof(fs) != 0)
	{	
		lecture_fse(fs, &g, tab);
	}
	
		affiche_matrice(&g);
        affiche_liste(&g);
}

