all : toto
toto : gui.o ia.o main.o score.o
	gcc gui.o ia.o main.o score.o -o toto

gui.o : gui.c gui.h
	gcc -c gui.c gui.h 

main.o : main.c
	gcc -c main.c 

ia.o : ia.c ia.h
	gcc -c ia.c ia.h 
	
score.o : score.c score.h
	gcc -c score.c score.h 


clean :
	rm -f toto *.o

