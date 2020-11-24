#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#define ERREUR_SAISIE_E -10

int saisieEntier();
void saisiePersonne();
void division();
void produit();
void prediction();
void compte();
int saisieMenu();
void menu(int cas);

#endif
