all : EXEC

flow_mission3.o : flow_mission3.c flow_mission3.h
	gcc -c flow_mission3.c flow_mission3.h

main_mission3.o : main_mission3.c
	gcc -o main_mission3.o -c main_mission3.c

EXEC : flow_mission3.o main_mission3.o
	gcc -o TP3graphe main_mission3.o flow_mission3.o

clean :
	rm -rf *.o
	rm -rf EXEC
	rm -rf *.h.gch
