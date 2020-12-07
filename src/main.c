#include "../include/liste.h"
#include "../include/test.h"

#include <stdio.h>

char * nom = "Classeur1";
int nbLigne = 50;
int nbColonne = 50;
node_t * listCellules;

int main(){
    listCellules = list_create();

    testStack();
    testListe();
    testCellule();
    testGraphe();
}