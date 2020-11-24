#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 3

void init (int plateau[N][N]){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			plateau[i][j]=-1;
		}
	}
	
}

void print (int plateau[N][N]){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			printf("%d |",plateau[i][j]);
		}
		printf("\n");
	}
	
}

void affichage(int plateau[N][N]){
	char T[N][N];
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(plateau[i][j]==-1){
				T[i][j]=' ';
			}else if (plateau[i][j]==1){
				T[i][j]='X';
			}else if (plateau[i][j]==2){
				T[i][j]='O';
			}
		}
			
	}		
	printf("\n");
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			
			printf("%c   |", T[i][j]);
			
		}
		printf("\n");
		printf("______________");
		printf("\n\n");
	}
				
}

int jouer(int plateau[N][N], int jouer, int x, int y){
	
	if(plateau[x][y]!=-1){
		printf("Case deja joue\n");
		return 0;
	}else{
		if(jouer==1){
			plateau[x][y]=1;
		}
		if(jouer==2){
			plateau[x][y]=2;
		}
	}	
	return 1;
}

bool verifieGagnant(int plateau[N][N]){
	for(int lig=0; lig<N; ++lig){
		if((plateau[lig][0] == 1)&&(plateau[lig][1] == 1)&&(plateau[lig][2] == 1)){
			printf("Le jouer 1 a gagner !\n");
			return true;
		}
		
	
		if((plateau[0][lig] == 1)&&(plateau[1][lig] == 1)&&(plateau[2][lig] == 1)){
			printf("Le jouer 1 a gagner !\n");
			
			return true;
		}
	
	
		if((plateau[0][0] == 1)&&(plateau[1][1] == 1)&&(plateau[2][2] == 1)){
			printf("Le jouer 1 a gagner !\n");
			
			return true;
		}
		
		if((plateau[0][2] == 1)&&(plateau[1][1] == 1)&&(plateau[2][0] == 1)){
			printf("Le jouer 1 a gagner !\n");
			
			return true;
		}
		
	// jouer 2
	 
		if((plateau[lig][0] == 2)&&(plateau[lig][1] == 2)&&(plateau[lig][2] == 2)){
			printf("Le jouer 2 a gagner !\n");
			
			return true;
		}
		
	
		if((plateau[0][lig] == 2)&&(plateau[1][lig] == 2)&&(plateau[2][lig] == 2)){
			printf("Le jouer 2 a gagner !\n");
			
			return true;
		}
	
	
		if((plateau[0][0] == 2)&&(plateau[1][1] == 2)&&(plateau[2][2] == 2)){
			printf("Le jouer 2 a gagner !\n");
			
			return true;
		}
		
		if((plateau[0][2] == 2)&&(plateau[1][1] == 2)&&(plateau[2][0] == 2)){
			printf("Le jouer 2 a gagner !\n");
			
			return true;
		}
		
	}
	return false;
		
}
	
void tourDeJeu(int plateau[N][N]){
	int x,y;
	int candidat=1;
	int valide;
	int cnt=0;
	
	do{
		
		if(verifieGagnant(plateau)){
			affichage(plateau);
			exit(-1);
		}
		
		if(candidat%2==1){
			printf("Jouer 1 veuillez faire un choix pour la ligne x: ");
			scanf("%d",&x);
			while((x!=1)&&(x!=2)&&(x!=3)){
				printf("Veuillez saisir une ligne dans le tableau :");
				scanf("%d",&x);
			}
			printf("Jouer 1 veuillez faire un choix pour la colonne y: ");
			scanf("%d",&y);
			while((y!=1)&&(y!=2)&&(y!=3)){
				printf("Veuillez saisir une colonne dans le tableau :");
				scanf("%d",&y);
			}
			candidat=1;
			valide=jouer(plateau,candidat,x-1,y-1);
		
			while(valide!=1){
				printf("Jouer 1 veuillez faire un choix pourla ligne x: ");
				scanf("%d",&x);
				while((x!=1)&&(x!=2)&&(x!=3)){
					printf("Veuillez saisir une ligne dans le tableau:");
					scanf("%d",&x);
				}
				printf("Jouer 1 veuillez faire un choix pour la colonne y: ");
				scanf("%d",&y);
				while((y!=1)&&(y!=2)&&(y!=3)){
					printf("Veuillez saisir une colonne dans le tableau :");
					scanf("%d",&y);
				}
			
				valide=jouer(plateau,candidat,x-1,y-1);
			}
		
			affichage(plateau);
			candidat++;
		
		
		}else{
			printf("Jouer 2 veuillez faire un choix pour la ligne x: ");
			scanf("%d",&x);
			while((x!=1)&&(x!=2)&&(x!=3)){
				printf("Veuillez saisir une ligne dans le tableau :");
				scanf("%d",&x);
			}
			printf("Jouer 2 veuillez faire un choix pour la colonne y: ");
			scanf("%d",&y);
			while((y!=1)&&(y!=2)&&(y!=3)){
				printf("Veuillez saisir une colonne dans le tableau :");
				scanf("%d",&y);
			}
			
			candidat=2;
			valide=jouer(plateau,candidat,x-1,y-1);
			
			while(valide!=1){
				printf("Jouer 2 veuillez faire un choix pour la ligne x: ");
				scanf("%d",&x);
				while((x!=1)&&(x!=2)&&(x!=3)){
					printf("Veuillez saisir une ligne dans le tableau :");
					scanf("%d",&x);
				}
				printf("Jouer 2 veuillez faire un choix pour la colonne y: ");
				scanf("%d",&y);
				while((y!=1)&&(y!=2)&&(y!=3)){
					printf("Veuillez saisir une colonne dans le tableau :");
					scanf("%d",&y);
				}	
			
				valide=jouer(plateau,candidat,x-1,y-1);
			}
			affichage(plateau);
			candidat++;
		}
		
		cnt++;
		
	}while(cnt!=9);
	
	if(cnt==9){
		printf("Fin du jeu\n");
		affichage(plateau);
		exit(-1);
	}				
}	

int main(int argc,char *argv[]){
	int plateau[N][N];
	init(plateau);
	printf(" **Le morpion**\n");
	affichage(plateau);
	tourDeJeu(plateau);

return 0;
}
