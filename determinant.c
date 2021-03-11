#include "fonctions.h"

void AfficheMatrice(double** M,int n){
	int lig,col;
	for(lig=0; lig<n; lig++){
		for(col=0; col<n; col++){
			
			if(col==0) printf("|");
			printf("%g\t|",M[lig][col]);
			
		}
		printf("\n");
	}
	printf("\n");
	
}


double **CreeMatrice(int n){
	double **M;
	int lig;
	M=malloc(sizeof(*M)*n);
	
	for(lig=0; lig<n; lig++){
		
		M[lig]=malloc(sizeof(**M)*n);
	}
	return M;
}


double **saisieMatrice(double **M,int taille){
	int lig,col;
	double tmp=0;
	for( lig=0; lig<taille; lig++){
		for(col=0; col<taille; col++){
			
			printf("Matrice[%d][%d]= ",lig+1,col+1);
			
			scanf("%lf",&tmp);
			M[lig][col]=tmp;
			
			//printf("%g\t",tmp);
		
		}
	}
	return M;
	
}


double **MatriceAleatoire(int n, double min, double max){
	double **M;
	M=CreeMatrice(n);
	
	int lig, col;
	for(col=0; col<n; col++){
		for(lig=0; lig<n; lig++){
			
			M[lig][col]=(double)((rand()%(int)max)+(int)min-1);
			
		}
	}
	return M;
}



double Determinant(double **M,int n){
	int lig,i,j,p,q,signe,det;
	double **T;
	double k;
	
	//double tempdet=0;
	
	T=CreeMatrice(n-1);
	det=0; // faut initialiser det
	signe=1;
	
	if(n==1||n==2){
		if(n==1){
			return M[0][0];
		}else{
			
			k=M[0][0]*M[1][1]-M[0][1]*M[1][0];
			//printf("det=ad-bc=%g\n\n",k);
			return k;
		
		}
	}else{
	
		for(lig=0; lig<n; lig++){
			p=0;
			q=0;
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					
					if(i==0||j==lig);
					
					else{
						
						T[p][q]=M[i][j];
						if(q<n-2){
							q++;
							
						}
						else{
							
							q=0;
							p++;
						}
					}		
				}
		
			}
		
		//printf("%d",det);
		//tempdet=T[0][0]*T[1][1]-T[0][1]*T[1][0];
		//printf("\ndet=ad-bc=%g*%g-%g*%g=%g\n",T[0][0],T[1][1],T[0][1],T[1][0],tempdet);
		printf("signe*M[%d][%d]*det=%d*%g*det\n",1,lig+1,signe,M[0][lig]);
		for(int k=0; k<n-1; k++){
			for(int h=0; h<n-1; h++){
				
				if(h==0) printf("|");
				printf("%g\t|", T[k][h]);
			
			}
			printf("\n");
		}
		printf("\n");
		//printf("signe*M[%d][%d]*det=%d*%g*%g=%g\n",1,lig+1,signe,M[0][lig],tempdet,signe*M[0][lig]*tempdet);

		det= det + signe*M[0][lig]*Determinant(T,n-1);
		
		signe*=-1;
		}
	}
	free(T);
	return det;	
}
double DeterminantSilencieux(double **M,int n){
	int lig,i,j,p,q,signe,det;
	double **T;
	double k;
	
	
	T=CreeMatrice(n-1);
	det=0; 
	signe=1;
	
	if(n==1||n==2){
		if(n==1){
			return M[0][0];
		}else{
			
			k=M[0][0]*M[1][1]-M[0][1]*M[1][0];
			return k;
		
		}
	}else{
	
		for(lig=0; lig<n; lig++){
			p=0;
			q=0;
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					
					if(i==0||j==lig);
					
					else{
						
						T[p][q]=M[i][j];
						if(q<n-2){
							q++;
							
						}
						else{
							
							q=0;
							p++;
						}
					}		
				}
		
			}
		
		
		det= det + signe*M[0][lig]*DeterminantSilencieux(T,n-1);
		
		signe*=-1;
		}
	}
	free(T);
	return det;	
}

double **CoMatrice(double **M, int n){
	int lig,col,i,j,l,m,signe;
	double **T, **Cofact;
	double **I;
	
	//initialisation des variables
	I=CreeMatrice(1);
	I[0][0]=1.0; // identite 1x1
	T=CreeMatrice(n);
	Cofact=CreeMatrice(n);
	signe=1;

	
	if(n==1||n==2){
		if(n==1){
			return I;
		}else{						// 	A    	comatrice(A)
			Cofact[0][0]=M[1][1];		// (a  b)	  = 	  (d  -c)
			Cofact[0][1]=-(M[1][0]);		// (c  d)	   	  (-b  a)
			Cofact[1][0]=-(M[0][1]);		
			Cofact[1][1]=M[0][0];		  
			return Cofact;
		
		}
	}else{
	
	for(lig=0; lig<n; lig++){// meme principe que pour le déterminanat
					//sauf qu'on doit faire pour le tableau en entier
		for(col=0; col<n; col++){
			l=0;
			m=0;
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					if(i==lig||j==col);// au lieu de seulement la ligne 1
									// on fait toute les lignes
					else{
						T[l][m]=M[i][j];
						if(m<n-2){
							m++;
						}else{
							m=0;
							l++;
						}
					}
				}
			}
			//printf("ligne %d, colonne %d\n",lig+1,col+1);
			Cofact[lig][col]=DeterminantSilencieux(T,n-1)*signe;
			//AfficheMatrice(Cofact,n);
			
			signe*=-1;
		}
	}
	
	}
	//AfficheMatrice(Cofact,n);
	free(T);
	return Cofact;
			
	
}



void inverseMatrice(double **M,int n){
	double **Cofact, **Inv;
	
	Cofact=CreeMatrice(n);
	
	Inv=CreeMatrice(n);
	
	Cofact=CoMatrice(M,n);
	
	int det=DeterminantSilencieux(M,n);
	
	if (det!=0){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				Cofact[i][j]=Cofact[i][j]*(1.0/det);
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(j==0) printf("|");
				Inv[i][j]=Cofact[j][i];
				printf("%g\t|",Inv[i][j]);
			}
			printf("\n");
		}
	
	}else{
		
		printf("La matrice n'est pas inversible\n");
	}
	
	free(Cofact);
	free(Inv);
}
