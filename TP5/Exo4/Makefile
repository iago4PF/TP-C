CC = gcc -Wall
RM = rm
SRC = score.c ia.c gui.c main.c
HEAD = score.h ia.h gui.h
OBJ = score.o ia.o gui.o main.o
PROG = toto

all : $(PROG)

$(PROG) : $(OBJ)
	$(CC) $^ -o $@
	#$^ site toute les dependenses (en .c et en .h) on peut metre $(OBJ)
	#$@ cible prog (on peut mettre $(PROG))
	
$(OBJ) : $(SRC) $(HEAD)
	$(CC) -c $(SRC)
	#$^ site toute les dependenses (en .c et en .h)
	
clean :
	$(RM) -f $(OBJ) $(PROG) *.gch
