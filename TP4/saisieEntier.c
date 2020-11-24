#include "main.h"
int saisieEntier(){
	char term;
	int n;
	printf("Veuillez rentrer un nombre entier : \n");
	if(scanf("%d%c",&n,&term)!=2 || !('\n'==term||(' '==term)||('\t'==term))){
		printf("Erreur de saisie %d \n",ERREUR_SAISIE_E);
		exit(ERREUR_SAISIE_E);
		
	}else{
		return n;
	}
}
