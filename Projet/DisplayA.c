#include <stdio.h>
#include "Struct.h"

/**
 * \fn DisplayArray(int tab[][15], Player tabPlayer[])
 * \brief Fonction permettant l'affichage du plateau.
 * 
 * \param tab[][15] Tableau à 2 dimensions représentant le plateau.
 * \param tabPlayer[] Tableau permettant d'identifier le joueur.
 */

void DisplayArray(int tab[][15], Player tabPlayer[]){
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
			if(tabPlayer[0].color==1 && 1==tab[i][j]){//Permet d'afficher les couleurs des écuries et des pions.
	      printf(GREEN"%d",tab[i][j]);
				printf(DEFAULT" ");
	    }
    	else if(tabPlayer[1].color==2 && 2==tab[i][j]){
	      printf(YELLOW"%d",tab[i][j]);
				printf(DEFAULT" ");
	    }
			else if(tabPlayer[2].color==3 && 3==tab[i][j]){
	      printf(BLUE"%d",tab[i][j]);
				printf(DEFAULT" ");
	    }
			else if(tabPlayer[3].color==4 && 4==tab[i][j]){
	 			printf(RED"%d",tab[i][j]);
				printf(DEFAULT" ");
	    }
			else{
      	printf(DEFAULT"%d",tab[i][j]);
      	printf(" ");
			}
    }
    printf("\n");
  }
}	
