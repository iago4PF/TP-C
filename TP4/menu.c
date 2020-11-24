#include "main.h"

int menu(){
	int cas;
puts("*************************************");
puts("1. Saisie d'un nombre entier");
puts("2. Saisie d'un nombre reel");
puts("3. Quitter");
puts("*************************************");

printf("Saisir votre choix : \n");
scanf("%d",&cas);

while ((cas !=1)&&(cas!=2)&&(cas!=3)){
	printf("Il faut saisir un choix valide dans le menu : 1 ou 2 \n");
	scanf("%d", &cas);
	}
return cas;

	
}
