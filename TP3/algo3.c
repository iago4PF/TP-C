#include <stdio.h>
void echange(int nb1, int nb2){
int tmp;
printf("Avant échange\n");
printf("Nb1 = %d\n",nb1);
printf("Nb2 = %d\n",nb2);
tmp=nb1;
nb1=nb2;
nb2=tmp;
printf("Après échange\n");
printf("Nb1 = %d\n",nb1);
printf("Nb2 = %d\n",nb2);
}
int main(int argc, char** argv){
int nb1=5,nb2=7;
printf("Avant appel de la fonction\n");
printf("Nb1 = %d\n",nb1);
printf("Nb2 = %d\n",nb2);
printf("Appel de la fonction\n");
printf("--------------\n");
echange(nb1,nb2);
printf("---------------\n");
printf("Après appel de la fonction\n");
printf("Nb1 = %d\n",nb1);
printf("Nb2 = %d\n",nb2);
}
