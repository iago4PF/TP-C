Pour compiler separement sans creer de biblitotheque :

	gcc -c main.c menu.c saisieEntier.c saisieReel.c
	gcc main.o menu.o saisieEntier.o saisieReel.o -o monProg
	./monProg

Pour creer une libraire statique contenant nos fonctions :

	ar r libgestionsaisie.a main.o menu.o saisieEntier.o saisieReel.o
	ranlib libgestionsaisie.a

Pour compiler notre fichier main avec la nouvelle bibliotheque statique crée :

	gcc -Wall -o monProg main.c -L. -lgestionsaisie  
(le point indique que la bibliotheque est dans le repertoire actuel, sans le point => erreur : -L. <-ne pas oublier le point)

Pour creer une libraire dynamique contenant nos fonctions :

	gcc -fPIC -c main.c menu.c saisieEntier.c saisieReel.c
	gcc -shared main.o menu.o saisieEntier.o saisieReel.o -o libgestion_dynamic.so


Compilation et execution avec création de biblio dynamique:

	gcc -fPIC -c main.c menu.c saisieEntier.c saisieReel.c
	gcc -shared main.o menu.o saisieEntier.o saisieReel.o -o libgestion_dynamic.so
	gcc -Wall -o monProg2 main.c -L. -lgestion_dynamic
	./monProg2
	
Compilation et execution avec création de biblio statique:

	gcc -c main.c menu.c saisieEntier.c saisieReel.c
	ar r libgestion_static.a main.o menu.o saisieEntier.o saisieReel.o
	ranlib libgestion_static.a
	gcc -Wall -o monProg1 main.c -L. -lgestion_static
	./monProg1
	
