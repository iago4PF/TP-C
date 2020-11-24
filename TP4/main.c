#include "main.h"

int main (){
	int cas;
	cas=menu();
	switch (cas){
		case 1:
			printf("Voici le nombre entier : %d\n",saisieEntier());
		break;
		case 2:
			printf("voici le nombre reel %f\n",saisieReel());
		break;
		default:
			printf("Aurevoir\n");
		break;
	}
}
