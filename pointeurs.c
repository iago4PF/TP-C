#include <stdio.h>
#include <stdlib.h>
int i,j;
void question1(){
	int i;
	int* pointeur;
	i=10;
	pointeur=&i;
	printf("entier i : %d\n",i);
	printf("pointeur : %d\n",*pointeur);
	*pointeur=5;
	printf("entier i : %d\n",i);
	printf("pointeur : %d\n",*pointeur);
	
}
void question2(){
	int a;
	int b;
	int* p;
	//int** pp;
	a=0;
	b=1;
	printf("au depart les entiers a=%d et b=%d\n",a,b);
	p=&a;
	a+=b;
	//pp=&p;
	printf("Après opérations : \n");
	printf("\tentier a=%d\n", a);
	printf("\tentier b=%d\n", b);
	printf("\tpointeur p=%d\n", *p);
	//printf("\tpointeur pp=%d\n", *p);
	
	
}
void question3(){
	int tab[5]={0,1,2,0,5};
	int* p=tab;
	int* pdebut=&tab[0];
	int* pfin=&tab[5];
	printf("On affiche le tableau avec les pointeurs:\n");
	for (int* pindex=pdebut; pindex<pfin; pindex++){
		if(pindex==pdebut) printf("|");
		printf("%d |",*(pindex));
	}
	printf("\n\n");
	printf("On affiche les éléments nuls du tableau:\n");
	for(int* p=pdebut; p<pfin; p++){
		if(p==pdebut) printf("|");
		if(*p==0){
			printf("tab[indice:%ld]=%d |",p-pdebut,p[*p]);// p-debut pour avoir l'indice p[*p]=p[p-debut]=p[i]
		}
	}
	printf("\n\n");
	printf("Les pointeurs se comportent comme des tableaux:\n");
	for(int i=0; i<5; ++i){
		if(i==0) printf("|");
		printf("%d |",p[i]);
	}
	printf("\n");
	
}


int main(){
	//question1();
	//question2();
	question3();
	
}	
