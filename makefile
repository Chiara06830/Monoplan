Monoplan : ./obj/liste.o ./obj/testListe.o ./obj/cellule.o ./obj/testCellule.o
	gcc -o Monoplan ./obj/liste.o ./obj/cellule.o ./obj/testCellule.o

./obj/testListe.o : ./src/testListe.c ./include/liste.h
	gcc -c ./src/testListe.c -o ./obj/testListe.o

./obj/testCellule.o : ./src/testCellule.c ./include/cellule.h
	gcc -c ./src/testCellule.c -o ./obj/testCellule.o

./obj/liste.o : ./src/liste.c ./include/liste.h
	gcc -c ./src/liste.c -o ./obj/liste.o

./obj/cellule.o : ./src/cellule.c ./include/cellule.h
	gcc -c ./src/cellule.c -o ./obj/cellule.o

clean : 
	rm ./obj/* Monoplan