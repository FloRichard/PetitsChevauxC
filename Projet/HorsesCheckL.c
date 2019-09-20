#include<stdio.h>
#include"Struct.h"

/**
 * \fn HorsesCheckL(Player tab[],int i)
 * \brief Fonction vérifiant si des chevaux sont présents dans l'écurie
 * \param tab Tableau permettant d'identifier le joueur.
 * \param i indice du Joueur.
 */

int HorsesCheckL(Player tab[],int i){
  int res;
	int j=0;
  while(j<4){
    if(tab[i].horses[j].out==0){//Verification des chevaux presents dans l'écurie
      res=j;//retourne le numéro du premier  cheval dispo qu'il a trouvé
			return res;

    }else{
     res=-1;
    }
		j++;
  }
   return res;
}
