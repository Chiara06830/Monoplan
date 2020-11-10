Monoplan : ./obj/liste.o ./obj/main.o
	gcc -o Monoplan ./obj/liste.o ./obj/main.o

./obj/main.o : ./src/main.c ./include/liste.h
	gcc -c ./src/main.c -o ./obj/main.o

./obj/liste.o : ./src/liste.c ./include/liste.h
	gcc -c ./src/liste.c -o ./obj/liste.o

clean : 
	rm ./obj/* Monoplan