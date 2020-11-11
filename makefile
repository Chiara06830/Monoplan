Monoplan : ./obj/liste.o ./obj/testListe.o
	gcc -o Monoplan ./obj/liste.o ./obj/testListe.o

./obj/testListe.o : ./src/testListe.c ./include/liste.h
	gcc -c ./src/testListe.c -o ./obj/testListe.o

./obj/liste.o : ./src/liste.c ./include/liste.h
	gcc -c ./src/liste.c -o ./obj/liste.o

clean : 
	rm ./obj/* Monoplan