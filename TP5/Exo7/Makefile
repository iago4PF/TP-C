CC = gcc -Wall
RM = rm -f

srcdir=./src/
bindir=./bin/
docdir=./doc/
savedir=./save/


SRC = $(wildcard $(srcdir)*.c)
HEAD = $(wildcard $(srcdir)*.h)
OBJ = $(subst $(srcdir),$(bindir),$(SRC:.c=.o))
PROG = $(bindir)toto



all : $(PROG)
$(PROG) : $(OBJ)
	$(CC) $^ -o $@
	
$(bindir)%.o : $(srcdir)%.c 
# on va dans bin et on cree des .o a partir de des fichier .c dans src
	$(CC) -c $^ -o $@
# $^ faire appel aux dependences
#$@ pour faire reférence a la cible

	
.PHONY : clean
clean :
	$(RM) $(OBJ) $(PROG) *.gch
