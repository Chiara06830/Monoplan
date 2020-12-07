#include <stdio.h>

#include "../include/graphe.h"
#include "../include/test.h"

int testGraphe(){
    printf("\n//----------DEBUT TESTES MODULE GRAPHE---------//\n");

    create_cellule("3.0", "D03");
    create_cellule("= 5.6 D03 - &", "A04");
    create_cellule("= A04 D03 + &", "A05");
    create_cellule("12.4", "D02");
    s_cell * c5 = create_cellule("= D02 A05 * &", "C05");

    eval_graphe(c5);
    printf("%f\n", c5->valeur);

    printf("//-----------FIN TESTES MODULE GRAPHE----------//\n");

    return 0;
}
