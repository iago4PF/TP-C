#include <math.h>
#include <stdio.h>
#include <stdlib.h>



void affichageTriangle(int n){

 
for(int i=1; i<=n; i++)
{
    for(int j=0; j<n-i; j++)
    {
        printf(" ");
    }
    for(int k=0; k<2*i-1; k++)
    {
        printf("*");
    }
    printf("\n");
}

}


void tableMultiplication(int n){
printf("La table de multiplication de %d est :\n",n);
for(int i=1; i<=10; i++){
	if (n <=0){
		exit(-1);
		}
	else{
		printf(" %d x %d = %d \n",i,n,i*n);
		
	    }

}
}
void estArmstrong(int n){
int val=0, tmp,a;
tmp=n;
while (tmp>0){
	a=tmp%10;
	val=val+(a*a*a);
	tmp=tmp/10;
	}
	if (n==val){printf("Le numero est Amstrong\n");}
	else{printf("Le numero n'est pas Amstrong\n");}
}

int main (){
int cas, taille;
puts("*************************************");
puts("1. Affichage d'un triangle");
puts("2. Multiplication");
puts("3. Nombre Amstrong");
puts("*************************************");

printf("Saisir votre choix : \n");
scanf("%d",&cas);
switch (cas){
	case 1:
		printf("Taille du triangle :\n");
		scanf("%d",&taille);
		affichageTriangle(taille);
	break;
	case 2:
		printf("Quelle table de multiplication ? valeur entiere :\n");
		scanf("%d",&taille);
		tableMultiplication(taille);
	break;
	case 3:
		printf("Numero entier a vérifier :\n");
		scanf("%d",&taille);
		estArmstrong(taille);
	break;
	default:
	break;
}
}
	

