CC=gcc
OPT=-Wall
EXEC=Jeu
SRC=Color.c Initialisations.c DisplayA.c Leave.c Check.c Move.c DiceR.c HorsesCheckL.c HorsesCheckM.c main.c

executer: compiler
	@echo "Exécution :"
	./$(EXEC)
compiler: $(SOURCE)
	@echo "{--------------------------------------------------------------------COMPILATION------------------------------------------------------------------------}"
	@echo -n "|\t"
	$(CC) $(OPT) $(SRC) -o $(EXEC)
	@echo "\
{-------------------------------------------------------------------------------------------------------------------------------------------------------}"
