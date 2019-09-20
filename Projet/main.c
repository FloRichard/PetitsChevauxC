/*!
 * \file main.c
 * \brief Main du projet algorithmique du jeu "Les Petits Chevaux" en C avec 4 joueurs.
 *
 * \version 1.0
 * \date 05/01/2019
 * \author Florian RICHARD et Julien MONTEIL
 */

/*!
 * \mainpage Programme : Jeu des petits chevaux, programmé en C. Affichage du plateau dans le shell.
 * \content Notre programme permet de jouer aux petits chevaux depuis l'interpréteur de commandes à 4 joueurs.\n
 * Chaque joueur choisit sa couleur et doit sortir ses 4 chevaux en faisant un 6 avec un dé et les faire se déplacer sur le plateau jusqu'à la ligne d'arrivée pour gagner. La partie se termine quand un joueur positionnne ses 4 chevaux sur la ligne d'arrivée.\n\n
 * Notre programme est loin d'être parfait, lorsque les pions arrivent vers leur case finale (avant d'atteindre les cases numérotées), il y a quelques problèmes d'affichage, malheureusement nous n'avons pas trouvé de solutions qui fonctionnent.\n
 * Lors de la démonstration de notre programme pendant la soutenance, différents scénarios seront montrés.\n\n
 * DEROULEMENT DU JEU : Pour sortir un pion de l’écurie et venir le placer sur la première case de son parcours, le joueur doit faire un 6 avec le dé. S’il n’a pas fait 6, il passe son tour. Pendant la partie, il faudra obligatoirement faire un 6 pour mettre un nouveau pion sur la piste. Les règles ci-dessous déﬁnissent le déplacement des pions sur le plateau.\n — Une fois un pion sorti, le joueur le fait avancer du nombre de cases égal aux pions du dé. S’il a plusieurs pions sortis, le joueur peut faire avancer, au choix, n’importe lequel de ses pions en piste. \n— Un joueur qui fait 6 rejoue automatiquement une deuxième fois et peut, au choix, faire sortir un cheval ou avancer de 6 cases. \n— Un pion dont la route est barrée par un autre pion adverse ne peut se déplacer et passera son tour si les points du dé l’amène au-delà du barrage. \n— En revanche, si le tirage au dé permet à un joueur de placer son pion exactement sur une case déjà occupée par un pion adverse,il renvoie le pion de l’adversaire à l’écurie et prend sa place. Celui qui retourne à l’écurie repart donc de zéro et doit obtenir de nouveau un 6 pour sortir. Toutefois, deux pions de la même couleur peuvent se poser sur la même case.\n
Placement des pions dans les cases numérotées: A la ﬁn d’un tour complet du jeu, les pions se placent sur les cases numérotées de 1 à 6.Chaque pion avance du nombre de cases égal aux points du dé sur la case numérotée correspondante, à condition que celle-ci soit libre. Il est également possible de déplacer un pion à l’intérieur des cases numérotées pour libérer de la place et faire entrer un autre pion.Si aucun déplacement n’est possible, le pion passe son tour.\n
Fin de la partie : Le premier joueur qui réussit à ranger ses quatre pions dans les 4 cases numérotées le plus près du centre du plateau de jeu gagne la partie.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Struct.h"
#include "Color.h"
#include "Initialisations.h"
#include "DisplayA.h"
#include "Leave.h"
#include "Check.h"
#include "Move.h"
#include "DiceR.h"
#include "HorsesCheckL.h"
#include "HorsesCheckM.h"

/*! 
 * \fn int main(void)
 * \brief Programme principal faisant appel à toutes les foncions.
 */

//MAIN//
int main(){
  srand(time(NULL));
  int dice;
  Cell path[56];//chemin
  Cell pathW1[6];//Chemins victoires, un pour chaque joueur
  Cell pathW2[6];
  Cell pathW3[6];
  Cell pathW4[6];
  int Array[15][15];//plateau
  Player tabPlayer[4];

  ColorChoice(tabPlayer);
  for(int i=0;i<4;i++){//initialisation numero cheval,statut,case de fin de tour complet du plateau(posEnd) : ecurie, peut etre en faire une fonction
    for(int j=0;j<4;j++){
      tabPlayer[i].nb=i+1;
      tabPlayer[i].horses[j].num=j+1;//initliatisation des numéros
      tabPlayer[i].horses[j].out=0;//tous les chevals sont dans l'écurie
      tabPlayer[i].victory=0;
      if(i==0){
	tabPlayer[i].posEnd=43;// à partir d'ici, position de passage au tableau pathWin
	tabPlayer[i].posBeg=44;
      }
      else if(i==1){
	tabPlayer[i].posEnd=1;
	tabPlayer[i].posBeg=2;
      }else if(i==2){
	tabPlayer[i].posEnd=15;
	tabPlayer[i].posBeg=16;
      }else if(i==3){
	tabPlayer[i].posEnd=29;
	tabPlayer[i].posBeg=30;
      }
    }
  }
//INITIALISATION STATUT DES CASES//
  for(int i=0;i<56;i++){
    path[i].statut=1;
  }

  for(int i=0;i<56;i++){//initliastation numero des pathwin
    path[i].num=0;
    if(i<6){
      pathW1[i].num=i+1;
      pathW2[i].num=i+1;
      pathW3[i].num=i+1;
      pathW4[i].num=i+1;
    }
  }

  InitArray(Array);//Initialisation terrain
  InitPath(Array,path);//initialisation du chemin
  InitPathWin(Array,pathW1,pathW2,pathW3,pathW4);
  DisplayArray(Array, tabPlayer);//Affichage
  tabPlayer[0].victory=0;//Initialise le compteur de victoire à 0, victoire à 4 quand les 4 chevaux sont dans le PathWin
  tabPlayer[1].victory=0;
  tabPlayer[2].victory=0;
  tabPlayer[3].victory=0;
    
	///////////BOUCLE PRINCIPALE////////////

  int ans;
  int i=0;
  int y;
  while(tabPlayer[i].victory<4){
    if(tabPlayer[i].color==1){//Permet d'afficher le texte dans la couleur du joueur pour son tour
      printf(GREEN"\n\nJoueur %d c'est à vous de jouer\n",i+1);
    }
    else if(tabPlayer[i].color==2){
      printf(YELLOW"\n\nJoueur %d c'est à vous de jouer\n",i+1);
    }
    else if(tabPlayer[i].color==3){
      printf(BLUE"\n\nJoueur %d c'est à vous de jouer\n",i+1);
    }
    else{
      printf(RED"\n\nJoueur %d c'est à vous de jouer\n",i+1);
    }
    dice=DiceRolling(i);
    if(dice==6){//Si le lancé de Dé est égal à 6
      printf("Voulez vous sortir un cheval ? ( Tapez 1 pour oui ou 0 pour non ) ");
      scanf("%d",&y);
      printf(DEFAULT "");
      if(y==0 && HorsesCheckM(tabPlayer,i)>0){//le joueur ne veux pas sortir de chevaux, on verifie si le joueur a au moins un cheval de sorti pour pouvoir appeller la fonction move
	printf("Quel cheval voulez vous déplacer ?( Entrez un chiffre compris entre 1 et 4 ) ");
	scanf("%d",&ans);
	printf(DEFAULT "");
	move(Array,path,tabPlayer,ans,dice,i,pathW1,pathW2,pathW3,pathW4);
      }else if(y==1){//si le joueur veut sortir un cheval	
	Leave(tabPlayer,Array,path,i,tabPlayer);//on place le cheval sur sa case départ
      }
      i--;//le joueur peut rejouer immédiatement			
    }else if(HorsesCheckM(tabPlayer,i)>0){//si il y a au moins un cheval de sorti
      printf("Quel cheval voulez vous déplacer ?( Entrez un chiffre compris entre 1 et 4 ) ");
      scanf("%d",&ans);
      move(Array,path,tabPlayer,ans,dice,i,pathW1,pathW2,pathW3,pathW4);
    }
    i++;
    if(i>3){
      i=0;
    }
  }
	for(int i=0;i<4;i++){
		if(tabPlayer[i].victory==4){
			printf("FIN DE LA PARTIE, le joueur %d a gagné !",i+1);
		}
	}
  return 0; 
}


