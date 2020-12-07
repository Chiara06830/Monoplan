Monoplan : ./obj/liste.o ./obj/testListe.o ./obj/stack.o ./obj/testStack.o ./obj/cellule.o ./obj/testCellule.o ./obj/main.o
	gcc ./obj/liste.o ./obj/cellule.o ./obj/stack.o ./obj/testCellule.o ./obj/testListe.o ./obj/testStack.o ./obj/main.o -o Monoplan -lm

./obj/testStack.o : ./src/testStack.c ./include/stack.h
	gcc -c ./src/testStack.c -o ./obj/testStack.o

./obj/testListe.o : ./src/testListe.c ./include/liste.h
	gcc -c ./src/testListe.c -o ./obj/testListe.o

./obj/testCellule.o : ./src/testCellule.c ./include/cellule.h
	gcc -c ./src/testCellule.c -o ./obj/testCellule.o

./obj/stack.o : ./src/stack.c ./include/stack.h
	gcc -c ./src/stack.c -o ./obj/stack.o

./obj/liste.o : ./src/liste.c ./include/liste.h
	gcc -c ./src/liste.c -o ./obj/liste.o

./obj/cellule.o : ./src/cellule.c ./include/cellule.h 
	gcc -c ./src/cellule.c -o ./obj/cellule.o

./obj/main.o : ./src/main.c ./include/test.h 
	gcc -c ./src/main.c -o ./obj/main.o

clean : 
	rm ./obj/* Monoplan