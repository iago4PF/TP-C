#include "fonctions.h"

int main (){	
	time_t begin,end;
	begin=time(NULL);
	menu(saisieMenu());
	end=time(NULL);
	unsigned long secondes=(unsigned long) difftime(end,begin);
	printf("Finished in %ld sec\n", secondes);
	return 0;	
}
