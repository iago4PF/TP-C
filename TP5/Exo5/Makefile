CC = gcc -Wall
RM = rm -f
SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
OBJ=$(SRC:.c=.o)
#OBJ = $(subst .c,.o,$(SRC)) 
#(subst FROM,TO,TEXT) permet de faire une substitution
PROG = toto



all : $(PROG)
$(PROG) : $(OBJ)
	$(CC) $^ -o $@
	
.c.o:
	$(CC) -c $^ -o $@
	

clean :
	$(RM) $(OBJ) $(PROG)
