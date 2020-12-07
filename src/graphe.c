#include <stdio.h>

#include "../include/graphe.h"

void calculDegNeg(s_cell * papa){
    papa = lecture_cellule(papa);
    node_t * liste = papa->listeCellule;
    while(liste->valeur != NULL){
        s_cell * fils = (s_cell*) list_get_data(liste);
        fils->degNeg = papa->degNeg + 1;
        calculDegNeg(fils);
        liste = list_next(liste);
    }
}

void eval_graphe(s_cell * cell) {
    //INITIALISATION
    calculDegNeg(cell);

    //créer un sous graphe qui ne contient qu'une cellule
    node_t * graphe = list_create();
    graphe = list_insert(graphe, cell);

    //ITERATION (tri topologique)
    while(graphe->suivant != NULL){
        //recupère la tête du graphe et l'évalue
        s_cell * couranteCell = (s_cell*) list_get_data(graphe);
        graphe = list_headRemove(graphe);
        printf("-- %p\n", graphe);
        eval_cellule(couranteCell);

        //recupère la liste des successeur
        node_t * fils = couranteCell->listeCellule;
        s_cell * noeud = (s_cell*)list_get_data(fils);
        //pour chaque succeseur on reduit le degre negatif
        while(fils->suivant != NULL){
            noeud->degNeg = noeud->degNeg - 1;
            if(noeud->degNeg == 0){//si on a fini de traiter le noeud
                printf("%s\n", noeud->coordonnees);
                graphe = list_insert(graphe, noeud);
                fils = list_next(fils);
            }
            noeud = (s_cell*)list_get_data(fils);
        }

        list_destroy(fils);
    }

    list_destroy(graphe);
}
