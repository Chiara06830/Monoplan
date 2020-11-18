#include <stdlib.h>
#include <errno.h>

#include "../include/cellule.h"

//créer la cellule
s_cell * create_cellule(char * saisie){
    s_cell * cell;
    if((cell = (s_cell *) malloc(sizeof(s_cell))) == NULL){
        return NULL;
    }

    cell->saisie = saisie;
    cell->valeur = 0.0;
    cell ->listeJetons = list_create();
    cell ->listeCellule = list_create();

    return cell;
}

//analyse la chaine de caractères associée à une cellule 
//(le contenu de la cellule)
s_cell * lecture_cellule(s_cell * cell){
    double value;
    if((value = strtod(cell->saisie, NULL)) == ERANGE){
        return NULL;
    }
    cell->valeur = value;

    return cell;
}