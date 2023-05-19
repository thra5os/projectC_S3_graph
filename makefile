all : TP3graphe

flow.o : flow.c flow.h
	gcc -c flow.c flow.h

main.o : main.c
	gcc -o main.o -c main.c

TP3graphe : flow.o main.o
	gcc -o TP3graphe main.o flow.o

clean :
	rm -rf *.o
	rm -rf TP3graphe
	rm -rf *.h.gch
