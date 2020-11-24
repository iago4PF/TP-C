/*!
\file tp1.c
\author   Iago GAMA DE SOUZA <gamadesouz@eisti.eu>
\version   0.1
\date  1 octobre 2020
\brief    Premmier cours 
∗/

/∗! inclusion des entetes de librairies */
#include <stdio.h>
/*! 
\fn int main(int argc, char** argv)
\author Iago GAMA DE SOUZA <gamadesouz@eisti.eu>
\version   0.1
\date  1 octobre 2020
\brief  fonction simple
\param argc nombre d'arguments en entree
\param argv veleur des arguments en entree

*/
int main(int argc, char** argv) 
{
    int n;
    int m;
    char choix;
    char choix_entier;
    do
    {
        /* Affichage du menu */
        printf(" --------Veuillez choisir une option dans le menu suivant : -------- \
        \n\t Rechercher un maximum <1> \
        \n\t Rechercher un minimun <2> \
        \n\t Quitter <0> ");
         /* Demande du choix a lutilistauer */
        printf("\n Votre choix :");
        rewind(stdin);// vide le tampon clavier, la derniere entree de lutilisateur
        choix = getchar();// recuper le caracter toucher pas lutilisateur
        choix_entier = choix-'0';
    
    switch(choix_entier)
    {
        case 1:
            printf("Bienvenue dans la fonction Max(x,y) \n");
            printf("Veuillez rentrer deux nombres :\n");
            scanf("%d%d",&n,&m);
                if (n>m) 
                {
                  printf("max(%d,%d)=%d\n",n,m,n);
                  printf("\t Retour au menu \n");
                }
                else 
                {
                    printf("max(%d,%d)=%d\n",n,m,m);
                    printf("\t Retour au menu \n");
                }
        break;
        case 2:
        printf("Bienvenue dans la fonction Min(x,y) \n");
            printf("Veuillez rentrer deux nombres :\n");
            scanf("%d%d",&n,&m);
                if (n>m) 
                {
                  printf("min(%d,%d)=%d\n",n,m,m);
                  printf("\t Retour au menu \n");
                }
                else 
                {
                    printf("min(%d,%d)=%d\n",n,m,n);
                    printf("\t Retour au menu \n");
                }
        break;

    }

    } while (choix!='0');
    
    
return(0);// si tout ce passe bien, la fonction retourne 0
}