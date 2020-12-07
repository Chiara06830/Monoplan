#include <stdio.h>

#include "graphe.h"

void eval_graphe(s_cell * cell) {
    cell = lecture_cellule(cell);
    //INITIALISATION
    int nbSommet = 0;
    node_t * liste;
    for(liste=cell->listeCellule; liste->suivant!=NULL; liste=liste->suivant){
        printf("%p\n", liste->suivant);
        nbSommet++;
    }
    int dNeg[nbSommet];

    printf("nb sommet = %d\n", nbSommet);

    /*// pour chaque sommet du graphe
    int i=0;
    for(n=cell->listeCellule; n->suivant!=NULL; n=n->suivant){
        s_cell * cellule = n->valeur;
        int nbPred = 0;
        //pour chacun de leur predeceseur
         for(node_t * n2=cellule->listeCellule; n2->suivant!=NULL; n2=n2->suivant) {
            nbPred++;
         }
         dNeg[i] = nbPred;
         i++;
    }

    printf("nb sommet = %d\n", nbSommet);

    //ITERATION
    if(nbSommet = 0) return;

    //evaluation de la cellule
    cell = eval_cellule(cell);

    //pour chaque successeur
    i=0;
    for(n=cell->listeCellule; n->suivant!=NULL; n=n->suivant) {
        //reduire dNeg
        dNeg[i] = dNeg[i]-1;
        if(dNeg[i] == 0){
            eval_graphe(n->valeur);
        }
        i++;
    }*/

    /*
    b <- c
    b = c d *
    c->liste = b
    */
}
