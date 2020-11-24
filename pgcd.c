#include <stdio.h>
#include <stdlib.h>

int pgcdr(int nb1, int nb2){
	if(nb2!=0)
		return pgcdr(nb2,nb1%nb2);
	else
		return nb1;
}
void pgcd(int nb1, int nb2){
	int resultat=0;
	for(int i=1; i <= nb1 && i <= nb2; ++i){
        if(nb1%i==0 && nb2%i==0)
            resultat = i;
    }
  
    printf("PGCD(%d ,%d) = %d sans recursivite\n", nb1, nb2 ,resultat);
}
void ppcm(int nb1, int nb2){
	int resultat=(nb1>nb2) ? nb1 : nb2;
	while(1){ // boucle infinie
		if(resultat%nb1==0 && resultat%nb2==0){
			printf("PPCM(%d,%d) = %d \n",nb1,nb2,resultat);
			break;
		}
		++resultat;
	}
}

int main (){
	int nb1, nb2;
	printf("Entre deux entier :");
	scanf("%d %d",&nb1,&nb2);
	pgcd(nb1,nb2);
	printf("PGCD(%d, %d) = %d recursivement\n",nb1,nb2,pgcdr(nb1,nb2));
	ppcm(nb1,nb2);
	return 0;
}
