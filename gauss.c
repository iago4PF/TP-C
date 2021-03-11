#include "fonctions.h"
double **CreeMatriceAug(int n){
	double **M;
	int lig;
	M=malloc(sizeof(*M)*n);//lignes
	
	for(lig=0; lig<n; lig++){
		
		M[lig]=malloc(sizeof(**M)*2*n);//colonne
		
	}
	return M;
}

void AfficheMatriceAug(double** M,int n){
	int lig,col;
	int N=2*n;
	
	for(lig=0; lig<n; lig++){
		for(col=0; col<N; col++){
			
			if(col==0) printf("|");
			printf("%g\t|",M[lig][col]);
			
		}
		printf("\n");
	}
	printf("\n");	
}

double **AugmenteMatrice(double **M, int n){
	double **Maug;
	Maug=CreeMatriceAug(2*n);// +n colonnes pour l'augmentation
						// mais lignes inutiles à partir de n
						// on ne les utilise ni affiche jamais
	int lig,col;
	
	
	for(lig=0; lig<n; lig++){
		for(col=0; col<n; col++){
			
			Maug[lig][col]=M[lig][col];
			
			if(lig==col){
				Maug[lig][col+n]=1;
			}else{
				Maug[lig][col+n]=0;
			}
		}
	}		
	return Maug;
}

double **Dilatation(double **M,int n, int ligne,double coeff){
	int lig,col;
	int N=2*n;
	
	for(lig=0; lig<n; lig++){
		for(col=0; col<N; col++){
			
			if(lig==ligne){
				
				M[lig][col]=coeff*M[lig][col];
				
			}
		}
		
	}
	//printf("Ligne(%d) * %g\n",ligne+1,coeff);
	//AfficheMatriceAug(M,n);
	return M;
}

double **Transvection(double **M, int n, int ligne, double coeff, int ligne2){
	int lig,col;
	int N=2*n;
	
	for(lig=0; lig<n; lig++){
			if(lig==ligne){
				for(col=0; col<N; col++){
					M[lig][col]=M[lig][col]+coeff*M[ligne2][col];
					
				}
				//printf("Ligne(%d) + %g * Ligne(%d)\n",ligne+1,coeff,ligne2+1);
			}
	}
	//AfficheMatriceAug(M,n);
	return M;
}


double **Triangulation(double **M, int n){
	double **Maug;
	double coeff;
	double coeff2;
	int lig,k=1;
	Maug=CreeMatriceAug(n);
	
	Maug=AugmenteMatrice(M,n);
	printf("Matrice augmentee ET Opérations linéaires\n");
	AfficheMatriceAug(Maug,n);
	
	for(lig=0; lig<n; lig++){
		
		if (Maug[lig][lig]==0){
			
			//if(lig==0){// on ajoute la ligne d'endesous lig+1
			
				while(k<n){// on va chercher la premiere ligne endessous non nulle
					
					if(Maug[lig+k][lig]==0){
						k++;
					}else{
						break;
					}
					
				}
					
				if(Maug[lig+k][lig]!=0){// on ajoute la ligne d'embas lig+k
				
					coeff=(1.0/M[lig+k][lig]);
					Maug=Transvection(Maug,n,lig,coeff,lig+k);
					printf("L(%d)= L(%d)+%g*L(%d)\n",lig+1,lig+1,coeff,lig+k+1);
					AfficheMatriceAug(Maug,n);
				}
			//}
		}
		if(Maug[lig][lig]!=0){
				if(Maug[lig][lig]!=1){
					coeff=(1.0/Maug[lig][lig]);
			
					Maug=Dilatation(Maug,n,lig,coeff);
					printf("L(%d)= %g*L(%d)\n",lig+1,coeff,lig+1);
					AfficheMatriceAug(Maug,n);
				}
				for(int i=lig+1; i<n; i++){
					
					if(Maug[i][lig]==0);
					
					else{
						coeff2=-(Maug[i][lig]);
						Maug=Transvection(Maug,n,i,coeff2,lig);
						printf("L(%d)= L(%d)+%g*L(%d)\n",i+1,i+1,coeff2,lig+1);
						AfficheMatriceAug(Maug,n);
					}
				}			
		}
		

	}
	
	for(lig=0; lig<n; lig++){
		if(Maug[lig][lig]==0){
			if(Maug[lig-1][lig]!=0){// on ajoute la ligne d'audessus lig-1
				
				coeff=(1.0/M[lig-1][lig]);
				Maug=Transvection(Maug,n,lig,coeff,lig-1);
				printf("L(%d)= L(%d)+%g*L(%d)\n",lig+1,lig+1,coeff,lig);
				AfficheMatriceAug(Maug,n);
				
			}
		}
	}


	
	/*
	for(lig=0; lig<n; lig++){
		if(Maug[lig][lig]==0){
			Maug=Triangulation(Maug,n);
		}
	}
	*/
	
		
	return Maug;
}

double **Gauss(double **M, int n){
	double det=1.0*DeterminantSilencieux(M,n);
	double **Maug;
	int lig , col;
	double coeff;
	int N=n;
	if(det==0){
		
		printf("La matrice n'est pas inversible, det(A)=0\n");
		exit(-1);
		
	}else{
		
		printf("La matrice est inversible, det(A)=%g\n",det);
		
		Maug=CreeMatriceAug(n);
		Maug=Triangulation(M,n);	
		printf("Triangulation\n");
		AfficheMatriceAug(Maug,n);
		
		
		while(N>=1){
			
			for(lig=0; lig<n; lig++){
				for(col=0; col<n; col++){
					
					if(lig<=N-2&&col==N-1){
						//printf("M[%d][%d]=%g\n",lig,col,Maug[lig][col]);
						if((Maug[lig][col])!=0){
							
							coeff=-(Maug[lig][col]);
							Maug=Transvection(Maug,n,lig,coeff,N-1);
						}
					
					}
			
				}
		
			}
		N--;
		}
		
	}
	printf("Gauss\n");
	AfficheMatriceAug(Maug,n);
	return Maug;			
}

void InverseGauss(double **M, int n){
	
	printf("Matrice \n");
	AfficheMatrice(M,n);
	
	double **A;
	A=CreeMatriceAug(n);
	A=Gauss(M,n);
	
	int lig,col;
	int N=2*n;
	
	printf("Matrice inverse\n");
	for(lig=0; lig<n; lig++){
		for(col=n; col<N; col++){
			
			if(col==n) printf("|");
			printf("%g \t|",A[lig][col]);
			
		}
		printf("\n");
	}
}

void printAide(char *nomProg){
		printf("********************************************\n");
		printf(" Calcul du determinant d'une matrice NxN\n");
		printf(" Les arguments reconnu par le programme \n");
		printf("gauss : Méthode du déterminant\n");
		printf("determinant : Methode du pivot de gauss\n");
		printf("exemple de saisie \n");
		printf(" ./monProg -n 4 gauss\n");
		printf(" ./monProg -n 3 determinant\n");
		printf("Si votre matrice est contenue dans un ficher txt\n");
		printf(" ./monProg -n 2 gauss <matrice.txt\n");
	}
	
void printErreur(char *nomProg, char *erreur){
		printf("Erreur:'%s'\n", erreur);
		printAide(nomProg);
}
