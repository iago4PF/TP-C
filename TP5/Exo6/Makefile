CC = gcc -Wall
RM = rm -f
SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
OBJ=$(SRC:.c=.o)
PROG = monProg



all : $(PROG)
$(PROG) : $(OBJ)
	$(CC) $^ -o $@
	
.c.o:
	$(CC) -c $^ -o $@
	
.PHONY : clean
clean :
	$(RM) $(OBJ) $(PROG)
