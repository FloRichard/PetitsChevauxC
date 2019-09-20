#include <stdio.h>
#include"Struct.h"

/**
 * \fn InitPath(int tab[][15], Cell path[56])
 * \brief Fonction initialisant le parcours des pions.
 * \param path[56] tableau représentant le parcours des pions.
 * \param tab[][15] Tableau 2D du plateau
 */

void InitPath(int tab[][15],Cell path[56]){
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      if(i==0 && j<=8 && j>=6){
	tab[i][j]=path[j-6].num;//path 0,1,2
      }else if(i>=1 && i<=5 && j==8){
	tab[i][j]=path[i+2].num;// path 3,4,5,6,7
      }else if(i==6 && j>=8 && j<=14){
	tab[i][j]=path[j].num;//path 8,9,10,11,12,13,14
       }else if(i==7 && j==14){
	tab[i][j]=path[15].num;//path 15
      }else if(i==8 && j>=8 && j<=14 ){
	tab[i][j]=path[30-j].num;//path 16,17,18,19,20,21,22
      }else if(i>=9 && i<=14 && j==8){
	tab[i][j]=path[i+14].num;//path 23,24,25,26,27,28
      }else if(i==14 && j==7){
	tab[i][j]=path[29].num;//path 29
      }else if(i>=9 && i<=14 && j==6){
	tab[i][j]=path[44-i].num;//path 30,31,32,33,34,35
      }else if(i==8 && j>=0 && j<=6){
	tab[i][j]=path[42-j].num;//path 36,37,38,39,40,41,42
       }else if(i==7 && j==0){
	tab[i][j]=path[43].num;// path 43
      }else if(i==6 && j>=0 && j<=6){
	tab[i][j]=path[44+j].num;//path 44,45,46,47,48,49,50
      }else if(i>=1 && i<=5 && j==6){
      tab[i][j]=path[56-i].num;//path 51,52,53,54,55, jusqu'ici chemin
      }
    }
  }      
}

/**
 * \fn InitPathWin(int tab[][15], Cell t1[], Cell t2[], Cell t3[], Cell t4[])
 * \brief Fonction initialisant le chemin de victoire de chaque joueur.
 * 
 * \param tab[][15] Tableau 2D du plateau.
 * \param t1[] Chemin de victoire du Joueur 1.
 * \param t2[] Chemin de victoire du Joueur 2.
 * \param t3[] Chemin de victoire du Joueur 3.
 * \param t4[] Chemin de victoire du Joueur 4.
 */

void InitPathWin(int tab[][15],Cell t1[],Cell t2[],Cell t3[],Cell t4[]){//initialisation chemin victoire
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      if(i==7 && j>0 && j<7){
	tab[i][j]=t1[j-1].num;
      }else if(i==7 && j>7 && j<14){
	tab[i][j]=t3[13-j].num;//pour faire aller le tableau dans le bon sens
      }else if(j==7 && i>0 && i<7){
	tab[i][j]=t2[i-1].num;
      }else if(j==7 && i>7  && i<14){
	tab[i][j]=t4[13-i].num;
      }
    }
  }
}

/**
 * \fn InitArray(int tab[][15])
 * \brief Fonction initialisant le plateau de jeu.
 * 
 * \param tab[][15] Tableau 2D du plateau.
 */

void InitArray(int tab[][15]){
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
 
      if(j>5 && j<9){
	tab[i][j]=0;
      }
      else if(i>5 && i<9){
	tab[i][j]=0;
      }
      else if((i>-1 && i<6) && (j>-1 && j<6)){
	tab[i][j]=1;
      }
      else if((i>8 && i<15) && (j>-1 && j<6)){
	tab[i][j]=4;
      }
      else if((i>8 && i<15) && (j>8 && j<15)){
	tab[i][j]=3;
      }
      else if((i>-1 && i<6) && (j>8 && j<15)){
	tab[i][j]=2;
      }else if(i==7 && j==7){
	tab[i][j]=7;
      }
    }
  }
}
