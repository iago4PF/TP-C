#include "main.h"
float saisieReel (){
	char term;
	float re;
	printf("Veuillez rentrer un nombre reel : \n");
	if(scanf("%f%c",&re,&term)!=2 || !('\n'==term||(' '==term)||('\t'==term))){
		printf("Erreur de saisie %d \n", ERREUR_SAISIE_R);
		exit(ERREUR_SAISIE_R);
		
	}else{
		return re;
	}
}
