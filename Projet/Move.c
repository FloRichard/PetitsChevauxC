#include <stdio.h>
#include "Struct.h"
#include "Check.h"
#include "Initialisations.h"
#include "DisplayA.h"

/**
 * \fn move(int tab[][15],Cell tab2[56],Player tabPlayer[], int ans, int y, int I,Cell pathW1[6],Cell pathW2[6],Cell pathW3[6],Cell pathW4[6])
 * \brief Fonction permettant de déplacer un pion.
 * 
 * \param tab[][15] Tableau 2D du plateau.
 * \param tab2[56] Tableau représentant le parcours des pions.
 * \param tabPlayer[] Tableau permettant d'identifier le joueur.
 * \param ans numéro du cheval choisi par le joueur.
 * \param y résultat du lancer de dé.
 * \param I indice du joueur.
 * \param pathW1[6] Chemin de victoire du Joueur 1.
 * \param pathW2[6] Chemin de victoire du Joueur 2.
 * \param pathW3[6] Chemin de victoire du Joueur 3.
 * \param pathW4[6] Chemin de victoire du Joueur 4.
 */

void move(int tab[][15],Cell tab2[56],Player tabPlayer[],int ans,int y,int I, Cell pathW1[6],Cell pathW2[6],Cell pathW3[6],Cell pathW4[6]){/* y=dice*/
  int X=0;
	int rep;
  int pos;
	pos=(tabPlayer[I].horses[ans-1].posX);
  if((pos+y)>55){
    X=(pos+y-55);
  }else{
		X=pos+y;
  }
	rep=check(tabPlayer,tab2,pos,X,I,ans,y);
    if(rep==1){
     	tabPlayer[tab2[X].num-1].horses[tab2[X].horseNum].out=0;//retour à l'écurie,ici on utilise le horsenum
			printf("Votre cheval a mangé le cheval %d du joueur %d \n",tab2[X].horseNum,tab2[X].num-1);
      tab2[X].num=tabPlayer[I].nb;//le cheval prend la place donc le numero change
      tab2[pos].num=0;//le numero de l'ancienne case change
      tabPlayer[I].horses[ans-1].posX=X;
			printf("position arrivé : %d\n",tabPlayer[I].horses[ans-1].posX);
    }else if(rep==2){
      tab2[X].num=tabPlayer[I].nb;
			tab2[X].horseNum=tabPlayer[I].horses[ans-1].num;
      tab2[pos].num=0;
			tab2[pos].horseNum=tabPlayer[I].horses[ans-1].num;
      tabPlayer[I].horses[ans-1].posX=X;
			tab2[pos].statut=1;//la case de départ devient diponible
      printf("Vos 2 chevaux sont sur la case %d\n",tabPlayer[I].horses[ans-1].posX);
    }else if(rep==3){
      printf("Vous ne pouvez pas passer un cheval adverse vous barre la route,vous passez votre tour\n");
    }else if(rep==4){
			printf("COUCOU\n");
			tab2[tabPlayer[I].posEnd].num=tabPlayer[I].nb;
			tab2[tabPlayer[I].posEnd].horseNum=tabPlayer[I].horses[ans-1].num;//mise à jour horsenum
      tab2[pos].num=0;
			tab2[pos].horseNum=tabPlayer[I].horses[ans-1].num;//mise à jour horsenum
			tabPlayer[I].horses[ans-1].posX=tabPlayer[I].posEnd;
			tab2[tabPlayer[I].posEnd].statut=0;//la case d'arrivé devient occupé
			tab2[pos].statut=1;//la case de départ devient diponible
			tabPlayer[I].horses[ans-1].T=2;
			printf(DEFAULT "");
			if(I==0 && tabPlayer[I].horses[ans-1].T==2){
				if(pathW1[y].statut==0){
					printf("Cette case est déjà occupée par un de vos pions.\n");		
				}
				else{
					pathW1[y].num=tabPlayer[I].nb;
					pathW1[y].horseNum=tabPlayer[I].horses[ans-1].num;	
					pathW1[y].statut=0;
					tab2[tabPlayer[I].posEnd].num=0;
					tab2[tabPlayer[I].posEnd].statut=0;
					tabPlayer[I].horses[pathW1[y].horseNum].posX=y;
					tabPlayer[I].horses[ans-1].out=0;
					tabPlayer[I].victory++;
				}
		 }else if(I==1 && tabPlayer[I].horses[ans-1].T==2){
				if(pathW2[y].statut==0){
					printf("Cette case est déjà occupée par un de vos pions.\n");		
				}
				else{
					pathW2[y].num=tabPlayer[I].nb;
					pathW2[y].horseNum=tabPlayer[I].horses[ans-1].num;	
					pathW2[y].statut=0;
					tab2[tabPlayer[I].posEnd].num=0;
					tab2[tabPlayer[I].posEnd].statut=0;
					tabPlayer[I].horses[pathW2[y].horseNum].posX=y;
					tabPlayer[I].horses[ans-1].out=0;
					tabPlayer[I].victory++;
				}
		 }else if(I==2 && tabPlayer[I].horses[ans-1].T==2){
				if(pathW3[y].statut==0){
					printf("Cette case est déjà occupée par un de vos pions.\n");		
				}
				else{
					pathW3[y].num=tabPlayer[I].nb;
					pathW3[y].horseNum=tabPlayer[I].horses[ans-1].num;	
					pathW3[y].statut=0;
					tab2[tabPlayer[I].posEnd].num=0;
					tab2[tabPlayer[I].posEnd].statut=0;
					tabPlayer[I].horses[pathW3[y].horseNum].posX=y;
					tabPlayer[I].horses[ans-1].out=0;
					tabPlayer[I].victory++;
				}	
			}else if(I==3 && tabPlayer[I].horses[ans-1].T==2){
				if(pathW4[y].statut==0){
					printf("Cette case est déjà occupée par un de vos pions.\n");		
				}
				else{
					pathW4[y].num=tabPlayer[I].nb;
					pathW4[y].horseNum=tabPlayer[I].horses[ans-1].num;	
					pathW4[y].statut=0;
					tab2[tabPlayer[I].posEnd].num=0;
					tab2[tabPlayer[I].posEnd].statut=0;
					tabPlayer[I].horses[pathW4[y].horseNum].posX=y;
					tabPlayer[I].horses[ans-1].out=0;
					tabPlayer[I].victory++;
				}
			}
		 }
		  else if(rep==0){
      tab2[X].num=tabPlayer[I].nb;
			tab2[X].horseNum=tabPlayer[I].horses[ans-1].num;//mise à jour horsenum
      tab2[pos].num=0;
			tab2[pos].horseNum=tabPlayer[I].horses[ans-1].num;//mise à jour horsenum
			tabPlayer[I].horses[ans-1].posX=X;
			tab2[X].statut=0;//la case d'arrivé devient occupé
			tab2[pos].statut=1;//la case de départ devient diponible
			printf(DEFAULT "");
    }   
  InitPath(tab,tab2);
	InitPathWin(tab,pathW1,pathW2,pathW3,pathW4);
  DisplayArray(tab,tabPlayer);
}
