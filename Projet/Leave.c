#include<stdio.h>
#include"Initialisations.h"
#include"DisplayA.h"
#include"Struct.h"
#include"HorsesCheckL.h"

/**
 * \fn Leave(Player tab[],int tab2[][15],Cell tab3[],int i, Player tabPlayer[])
 * \brief Fonction vérifiant si le joueur peut ou non sortir un cheval.
 * 
 * \param tab[] Tableau permettant d'identifier le joueur.
 * \param tab2[][15] Tableau 2D du plateau.
 * \param tab3[] Parcours des pions.
 * \param i Donne le numéro du joueur.
 * \param tabPlayer[] Tableau permettant d'identifier le joueur.
 */

void Leave(Player tab[],int tab2[][15],Cell tab3[],int i, Player tabPlayer[]){//fonction pour sortir un cheval
    //Appel de la fonction qui verifie la disponibilité des chevaux
			int rep;
			rep=HorsesCheckL(tab,i);
     	if(rep!=(-1)){
				  tab[i].horses[rep].posX=tab[i].posBeg;// on place le cheval disponible sur sa case de départ
				  tab[i].horses[rep].out=1;//Statut cheval=sorti
				  tab3[tab[i].posBeg].num=tab[i].nb;//Numéro du joueur present sur la case
				  tab3[tab[i].posBeg].horseNum=rep;//Numéro du cheval present sur la case
					printf("Le cheval n°%d est sorti\n",rep+1);
				  InitPath(tab2,tab3);
				  DisplayArray(tab2,tabPlayer);
			}
}
