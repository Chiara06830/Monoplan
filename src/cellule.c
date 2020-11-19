#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

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
    extern node_t * listCellules;

    //si c'est une formule
    if(*(cell->saisie) == '='){
        const char delim[2] = " ";
        //on decoup en petit bout et on les parcours
        char * token = strtok(cell->saisie, delim);
        while(token != NULL){
            printf("%s\n", token);
            /*s_token * jeton;
            //si c'est une value
            if(strtod(cell->saisie, NULL)){
                jeton->type = VALUE;
                jeton->value.cst = strtod(token, NULL);
            }
            //si c'est une reference
            else if((*token>='A'&& *token<='Z')  && ((*token+1)>='0'&& (*token+1)<='9') && (*(token+2)>='0'&& *(token+2)<='9')){
                jeton->type = REF;
                //pour chaque cellule trouver celle qui correspond
                for(node_t * n=listCellules; n->suivant!=NULL; n=n->suivant){
                    if(1){
                        jeton->value.ref = NULL;
                        break;
                    }
                }
            }
            //si c'est un operateur
            else if(strcmp(token, "*") || strcmp(token, "/") || strcmp(token, "+") || strcmp(token, "-")){
                jeton->type = OPERATOR;
            }else {
                return NULL;
            }
            cell->listeJetons = list_insert(cell->listeJetons, jeton);*/
            token = strtok(NULL, delim);
        }
    }else {
        //si il y a overflow
        if((value = strtod(cell->saisie, NULL)) == ERANGE){
            return NULL;
        }
        cell->valeur = value;
    }

    return cell;
}