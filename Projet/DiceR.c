#include <stdio.h>
#include <stdlib.h>

/**
 * \fn DiceRolling(int i)
 * \brief Fonction simulant un lancer de dé à 6 faces.
 * 
 * \param i Correspond au numéro du joueur.
 * \return Le résultat du lancer de dé.
 */

int DiceRolling(int i){
  int x;
  x = rand()%(6-1+1)+1;
  printf("Joueur %d vous avez fait %d\n",i+1,x);
  return x;
}
