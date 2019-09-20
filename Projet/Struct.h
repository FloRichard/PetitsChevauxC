#ifndef STRUCT_H
#define STRUCT_H

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define DEFAULT "\033[0;m"

typedef struct{
  int color;
  int num;
  int posX;//position sur plateau
  int out;//Cheval sorti(1), écurie(0) et arrivé(2)
	int T; //1:près de la case de fin poour vérifier, 0 : non
}Horse;

typedef struct{
  int color;
  int nb;
  int horseNb;//nombres de chevaux à jouer(optionel à mon avis, je n'en vois pas l'utilité pour l'instant)
  Horse horses[4];//chevaux du joueur i
  int posEnd;//case de fin
  int posBeg;//Case début
	int victory;//4 : victoire : quand les 4 chevaux sont dans le path win, 0 pas victoire(chevaux encore en course)
}Player;

typedef struct{
  int x;
  int num;
  int statut; //0:occupée,1:disponible
  int horseNum;//chaque case a un numero de cheval et un numero de joueur cf fction move
}Cell;

#endif
