#include<stdio.h>
#include"Struct.h"

/**
 * \fn HorsesCheckM(Player tab[],int i)
 * \brief Fonction permettant de savoir si des chevaux sont sortis et de donner leur numéro.
 * \param tab Tableau permettant d'identifier le joueur.
 * \param i indice du Joueur.
 */


int HorsesCheckM(Player tab[],int i){
	int cpt=0;
  for(int j=0;j<4;j++){
    if(tab[i].horses[j].out==1){//Verification des chevaux sortis de l'écurie
      cpt++;//nb de chevaux sorti
			printf("Le cheval n°%d est disponible pour avancer\n",j+1);
  	}
	}
   return cpt;
}
