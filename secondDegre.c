#include "fonctions.h"


solution2D equation2D(double a, double b, double c){
	//resolution equation coeffs reels
	double delta;
	solution2D solution;
	if( a!=0){
		delta=b*b-4*a*c;
	}
	//initialisation des variables
	solution.racine1.reel=0;
	solution.racine1.imaginaire=0;
	solution.racine2.reel=0;
	solution.racine2.imaginaire=0;
	if(delta > 0){
		
		solution.racine1.reel=(-b-sqrt(delta))/(2*a);
		solution.racine2.reel=(-b+sqrt(delta))/(2*a);
		
	}else if(delta == 0){
		
		solution.racine1.reel=(-b/2*a);
		solution.racine2.reel=(-b/2*a);
		
	}else{
		
		solution.racine1.reel=(-b/(2*a));
		solution.racine1.imaginaire=(sqrt(-delta)/(2*a));
		solution.racine2.reel=(-b/(2*a));
		solution.racine2.imaginaire=(sqrt(-delta)/(2*a));
		
	}
	return solution;
}

void afficheSolution2D(solution2D res){
	if(res.racine1.imaginaire!=0||res.racine2.imaginaire!=0){
		
		printf(" l'equation possede deux solutions complexes conjuguees \n");
		printf(" x1 = %g -i %g\n", res.racine1.reel, res.racine1.imaginaire);
		printf(" x2 = %g +i %g\n", res.racine2.reel, res.racine2.imaginaire);
		
	}else{
		
		printf(" l'equation possede deux solutions reelles conjugues\n");
		printf(" x1 = %g\n", res.racine1.reel);
		printf(" x2 = %g\n", res.racine2.reel);
	}
		
}
