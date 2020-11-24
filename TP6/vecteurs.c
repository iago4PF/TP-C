#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define M 20

void initTableau(int *tab){
	for(int i=0; i<M;++i){
		tab[i]=rand()%50;
	}
}

void afficheTableau(int *tab){
	for(int i=0; i<M; i++){
		printf("%d |",tab[i]);
	}
	printf("\n");
}

void inversionTableau(int *tab){	
	int tmp;
	for(int i=0; i<M/2; ++i){
		tmp=tab[i];
		tab[i]=tab[M-1-i];
		tab[M-1-i]=tmp;
		
	}
}

void Somme(int *tab, int *tab2){
	for(int i=0; i<M; ++i){
		tab[i]=tab[i]+tab2[i];
		printf("%d |", tab[i]);
	}
	
}

bool estTraversable(int *tab){
	int indice=0;
	for(int i=0; i<M; ++i){
		indice+=tab[i];
	}
	if(M==indice){
		return true;
	}else{
		printf("indice = %d et taille = %d\n",indice,M);
		return false;
	}
		
}

int estPalindrome(char *mot){
	int nb=0;
	int cnt=0;
	int N=strlen(mot);
	for(int i=0; i<N/2;++i){
		if(mot[i]!=mot[N-i-1]){
			nb++;
		}else{
			cnt++;
		}
	}
	if(nb==0){
		return 1;
	}else{
		return 0;
	}
}

int main(int argc,char *argv[]){
	srand(time(NULL));
	int tab[M];
	int tab2[M];
	char *mot="radar";
	
	initTableau(tab);
	printf("Tableau remplis aléatoirement\n");
	afficheTableau(tab);
	printf("\n\n");
	printf("Inversion du tableau\n");
	inversionTableau(tab);
	afficheTableau(tab);
	printf("\n\n");
	printf("Un deuxieme Tableau remplis aléatoirement\n");
	initTableau(tab2);
	afficheTableau(tab2);
	afficheTableau(tab);
	printf("\n\n");
	printf("Voici la somme des deux tableau\n");
	Somme(tab,tab2);
	printf("\n\n");
	if(estTraversable(tab)){
		printf("le premier tableau est traversable\n");
	}else{
		printf("le premier tableau n'est pas traversable\n");
	}
	if(estTraversable(tab2)){
		printf("le deuxième tableau est traversable\n");
	}else{
		printf("le deuxième tableau n'est pas traversable\n");
	}

	if(estPalindrome(mot)==1){
		printf("le mot %s est palindrome\n",mot);
	}else{
		printf("le mot %s n'est pas palindrome\n",mot);
	}
	
		

	return 0;
}
