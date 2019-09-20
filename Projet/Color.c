#include <stdio.h>
#include "Struct.h"

/**
 * \fn ColorChoice(Player tabPlayer[])
 * \brief Fonction permettant aux joueurs de choisir leur couleur.
 * \param tabPlayer[] Tableau permettant d'identifier le joueur.
 */

void ColorChoice(Player tabPlayer[]){
  int Color[4]={0,0,0,0};
  int Test[4]={0,0,0,0};
    for(int j=0;j<4;j++){
      printf("Joueur %d, choisissez votre couleur.(Vert=1,jaune=2,bleu=3,rouge=4) \n",j+1);
      if(Color[0]==0){
	printf(GREEN"Le vert est disponible.\n");
      }
      if(Color[1]==0){
	printf(YELLOW"Le jaune est disponible.\n");
      }
      if(Color[2]==0){
	printf(BLUE"Le bleu est disponible.\n");
      }
      if(Color[3]==0){
	printf(RED"Le rouge est disponible.\n");
      }
      do{
	printf(DEFAULT"Entrez votre choix : \n");
	scanf("%d",&tabPlayer[j].color);
	Test[j]=tabPlayer[j].color;
      }while(((tabPlayer[j].color<1 || tabPlayer[j].color>4) || (Test[0]==tabPlayer[1].color)));
      Color[tabPlayer[j].color-1]=tabPlayer[j].color;
    }
}
