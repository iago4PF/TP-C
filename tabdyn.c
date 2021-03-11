#include <stdio.h>
void create(int* tab, int taille){
	for(int i=0; i<taille; ++i){
		printf("Veuillez saisir un entier:");
		scanf("%d",tab+i);
	}	
}
void affTab(int* tab, int taille){
	for(int i=0; i<taille; ++i){
		printf("| %d",*(tab+i));
	}
	printf("|\n\n");
}

void triInsert(int* tab, int taille){
	int tmp;
	int i,j;
	for( i=1; i<taille; ++i){
		tmp=*(tab+i);
		for( j=i;tab[j-1]>tmp&&j>=0;--j){
			tab[j]=tab[j-1];	
		}
		tab[j]=tmp;
	}
}

int main (){
	int N;
	int tab[20];
	int* p=tab;
	
	printf("Veuillez rentrer la taille du tableau:");
	scanf("%d",&N);
	create(p,N);
	
	affTab(p,N);
	
	triInsert(p,N);
	
	affTab(p,N);
	
}
