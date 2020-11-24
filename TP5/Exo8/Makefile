#variables
CC = gcc -Wall
RM = rm -f
CP = cp -fu

#dossiers
srcdir=./src/
bindir=./bin/
docdir=./doc/
savedir=./save/

#prendre les fichiers , variables de dependences
SRC = $(wildcard $(srcdir)*.c)
HEAD = $(wildcard $(srcdir)*.h)
OBJ = $(subst $(srcdir),$(bindir),$(SRC:.c=.o))
PROG = $(bindir)toto


#compilation du programme
all : $(PROG)
$(PROG) : $(OBJ)
# $^ faire appel aux dependences
#$@ pour faire reférence a la cible
	$(CC) $^ -o $@
	
$(bindir)%.o : $(srcdir)%.c 
# on va dans bin et on cree des .o a partir de des fichier .c dans src
	$(CC) -c $^ -o $@

.PHONY : clean save 
# phony pour faire appel aux cibles

save : $(srcdir)*.* 
# on recupere tout les fichier du repertoire src
	$(CP) $(srcdir)*.* $(savedir) 
#Commande / dependance / cible
#ici les dependances de save sont les fichiers dans src
#on va recuperer tout les fichier .c et .h dans src et on les copier dans save

	

clean :
	$(RM) $(OBJ) $(PROG) 
