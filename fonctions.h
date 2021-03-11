#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nombreComplexe{
	
	double reel;
	double imaginaire;
	
};

typedef struct nombreComplexe nbComplex;

struct solutionEqu2D{
	
	nbComplex racine1;
	nbComplex racine2;
	
};

typedef struct solutionEqu2D solution2D;

solution2D equation2D(double a, double b, double c);
void afficheSolution2D(solution2D res);

#endif
