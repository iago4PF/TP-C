CC = gcc -Wall 
RM = rm -f
SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
OBJ=$(SRC:.c=.o)
PROG = monProg



all : $(PROG)
$(PROG) : $(OBJ)
	$(CC) $^ -o $@ -lm
	
.c.o:
	$(CC) -c $^ -o $@ -lm
	
.PHONY : clean
clean :
	$(RM) $(OBJ) $(PROG)
