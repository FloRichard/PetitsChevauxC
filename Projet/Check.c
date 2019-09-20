#include "Struct.h"
#include <stdio.h>

/**
 * \fn check(Player tabPlayer[],Cell tab[56],int pos,int X,int I,int ans,int dice)
 * \brief Fonction vérifiant si le déplacement d'un pion est possible.
 * 
 * \param tabPlayer[] Tableau permettant d'identifier le joueur.
 * \param tab[] Le chemin que les pions parcourent.
 * \param pos Position du cheval avant le lancer dé.
 * \param X Position du cheval après le lancer de dé.
 * \param I Indice du joueur.
 * \param ans numéro du cheval qui a été choisi
 * \param dice résultat du lancer de dé
 * \return 1, 2, 3 ou 4 selon la situation et permet ou non le déplacement.
 */

int check(Player tabPlayer[],Cell tab[56],int pos,int X,int I,int ans,int dice){//x+y=position d'arrivée, i dans tab joueur
	int rep,test;
	test=tabPlayer[I].posEnd-10;
	if(test<0){
		test=45;
	}
	if(tabPlayer[I].horses[ans-1].posX>=test && tabPlayer[I].horses[ans-1].posX<=tabPlayer[I].posEnd){
		tabPlayer[I].horses[ans-1].T=1;//Variable qui dit qui le cheval est prêt de la case de fin
	}
	if(tab[X].statut==0 && tab[X].num!=tabPlayer[I].nb && tab[X].num>0){//si la case d'arrivée est occupée et le numéro du joueur qui joue est différent du numéro du joueur deja present
   rep=1;
  }else if(tab[X].statut==0 && tab[X].num==tabPlayer[I].nb){//si la case d'arrivée est occupé et que les numéros sont égaux 
    rep=2; 
	}else if((tabPlayer[I].horses[ans-1].posX>=tabPlayer[I].posEnd && tabPlayer[I].horses[ans-1].T==1)  || (tabPlayer[I].horses[ans-1].posX==tabPlayer[I].posEnd && tabPlayer[I].horses[ans-1].T==1)){//si le pion arrive ou dépasse la case finale
		rep=4;
  }else{
		  for(int i=0;i<4;i++){
		   	 for(int j=0;j<4;j++){
					if(tabPlayer[i].horses[j].out==1 && tab[tabPlayer[i].horses[j].num].num!=tabPlayer[I].nb){//verification de la position des chevaux pour savoir si le cheval joueur n'a pas d'obstacle
						if(tabPlayer[i].horses[j].posX>pos && tabPlayer[i].horses[j].posX<X){
							rep=3;
							return rep;
						}
		   		}else{
							rep=0;
					}
		 			
				}
			}	
		}
	return rep;
}
