#include "fonctions.h"
int saisieEntier(){
	int a,b=0;
	char  term;
	printf("Veuilez rentrer un nombre entier : \n");
	b=scanf("%d%c",&a,&term);
	if (b!=2 || !((' '==term) || ('\n'==term) || ('\t'==term))){
		printf("Erreur de saisie : %d \n",ERREUR_SAISIE_E);
		exit(ERREUR_SAISIE_E);		
	}else{
		return a;		
	}	
}
void saisiePersonne(){
	char nom[30], prenom[30], date[13];
	printf("Entrez votre nom:\n");
	fgets(nom,30,stdin);
	printf("Entre votre prenom:\n");
	fgets(prenom,30,stdin);
	printf("Entre votre date de naissance\n");
	fgets(date,13,stdin);
	printf("Voici ce que vous avez entré : \n");
	printf("Nom: %s\n",nom);
	printf("Prenom : %s\n",prenom);
	printf("Date de naissance : %s\n",date);
	
}
void division(){
	int a,b;
	printf("Veuillez saisir le numerateur : \n");
	scanf("%d",&a);
	printf("Veuillez saisir le denominateur : \n");
	scanf("%d",&b);
	
	
	if (b!=0){
		printf(" %d / %d = %f \n",a,b,(double)a/b);
	}else{
		printf("Division par 0 impossible !\n");
	}
	
}

void produit(){
	float a,b;
	printf("Veuillez saisir le premier nombre: \n");
	scanf("%f",&a);
	printf("Veuillez saisir le deuxième nombre : \n");
	scanf("%f",&b);
	if (a*b>0){
		printf("Le produit est positif \n");
	}else if(a*b==0){
		printf("Le produit est nul \n");
	}else{
		printf("Le produit est negatif \n");	
	}
}
void prediction(){
	int h,m;
	printf("Veuillez saisir l'heure: \n");
	scanf("%d",&h);
	printf("Veuillez saisir les minutes : \n");
	scanf("%d",&m);
	
	
	printf("Dans une minute, il sera %d heure(s) %d \n",h,m+1);
}
void compte(){
	int n,i;
	printf("Veuillez rentrer un entier\n");
	scanf("%d",&n);
	puts("***************************************\n");
	puts("c'est parti!");
	for(i=n; i>=0; i--){
		printf("%d\n",i);
		sleep(1);
	}
}
int saisieMenu(){
	int  cas;
puts("************************");
puts("**********Menu**********");
puts("1. Verification de saisie d'un entier");
puts("2. Verification de nom, prenom, date de naissance");
puts("3. Effectuer la division de deux nombre");
puts("4. Effectue la multiplication de deux nombres");
puts("5. Prediction d'heure");
puts("6. Compte à rebours");
puts("7. Quitter");
puts("************************");
puts(" ");

puts("Veuillez faire un choix : ");
scanf("%d",&cas);
	while ((cas!=1)&&(cas!=2)&&(cas!=3)&&(cas!=4)&&(cas!=5)&&(cas!=6)&&(cas!=7)){
		printf("Veuillez rentrer un choix valable: 1,2,3,4,5,6 et 7\n");
		scanf("%d",&cas);
	}
	return cas;
}
void menu(int cas){
	int a;
	switch(cas){
		case 1 :
			a=saisieEntier();
			printf("%d\n",a);
		break;
		case 2 :
			saisiePersonne();
		break;
		case 3 :
			division();
		case 4 :
			produit();
		break;
		case 5 : 
			prediction();
		break;
		case 6 :
			compte();
		break;
		default :
			printf("Au revoir\n");
		break;
				
				
	}
	
}
