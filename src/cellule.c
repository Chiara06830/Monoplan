#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "cellule.h"

extern node_t * listCellules;

/* ---------------------------------------------------
 * Créer un cellule et l'ajoute a la liste des cellules
 * ---------------------------------------------------
 * saisie   : chaine de caractère entrée dans la cellule
 * coor		: coordonnées de la cellule (ex: A01)
 * ---------------------------------------------------
 * retourne une cellule avec une valeur egale a 0
 * ----------------------------------------------------
 */
s_cell * create_cellule(char * saisie, char * coor){
    s_cell * cell;
    if((cell = (s_cell *) malloc(sizeof(s_cell))) == NULL){
        return NULL;
    }

    cell->coordonnees = strdup(coor);
    cell->saisie = saisie;
    cell->valeur = 0.0;
    cell->listeJetons = list_create();
    cell->listeCellule = list_create();

    //ajouter la cellules a la liste
    listCellules = list_insert(listCellules, cell);

    return cell;
}

/* ---------------------------------------------------
 * Créer un jeton
 * ---------------------------------------------------
 * ---------------------------------------------------
 * retourne un jeton de type VALUE avec comme valeur 0.0
 * ----------------------------------------------------
 */
s_token * create_jeton(){
    s_token * jeton;
    if((jeton = (s_token *) malloc(sizeof(s_token))) == NULL){
        return NULL;
    }

    jeton->type = VALUE;
    jeton->value.cst = 0.0;

    return jeton;
}

/* ---------------------------------------------------
 * Retrouve une cellule grace a ses coordonnées
 * ---------------------------------------------------
 * coor		: coordonnées de la cellule (ex: A01)
 * ---------------------------------------------------
 * retourne la cellule si elle est trouvé.
 * Une cellule avec une valeur de 0 si elle n'est pas
 * trouvé.
 * ----------------------------------------------------
 */
s_cell * trouver_cell(char * coor, s_cell * cell){
    //pour chaque cellule trouver celle qui correspond
    for(node_t * n=listCellules; n->suivant!=NULL; n=n->suivant){
        s_cell * cell = n->valeur;
        if(!strcmp(cell->coordonnees, coor)){//si c'est la meme
            return cell;
        }
    }

    return create_cellule("", coor);
}

/* ---------------------------------------------------
 * multiplie les valeurs dans la pile
 * ---------------------------------------------------
 * stack : la pile avec les valeurs a multiplier
 * ---------------------------------------------------
 */
void multiplication(my_stack_t *stack){
    double total = 1;
    while(!STACK_EMPTY(stack)){
        total *= STACK_POP(stack, double);
    }
    STACK_PUSH(stack , total, double);
}

/* ---------------------------------------------------
 * divise les valeurs dans la pile
 * ---------------------------------------------------
 * stack : la pile avec les valeurs a diviser
 * ---------------------------------------------------
 */
void division(my_stack_t *stack){
    double valeur = STACK_POP(stack, double);
    double total = STACK_POP(stack, double);
    total = total / valeur;
    STACK_PUSH(stack , total, double);
}

/* ---------------------------------------------------
 * additionne les valeurs dans la pile
 * ---------------------------------------------------
 * stack : la pile avec les valeurs a additionner
 * ---------------------------------------------------
 */
void adition(my_stack_t *stack){
    double total = 0;
    while(!STACK_EMPTY(stack)){
        total += STACK_POP(stack, double);
    }
    STACK_PUSH(stack , total, double);
}

/* ---------------------------------------------------
 * soustrait les valeurs dans la pile
 * ---------------------------------------------------
 * stack : la pile avec les valeurs a soustraire
 * ---------------------------------------------------
 */
void soustraction(my_stack_t *stack){
    double valeur = STACK_POP(stack, double);
    double total = STACK_POP(stack, double);
    total = total - valeur;
    STACK_PUSH(stack , total, double);
}

/* ---------------------------------------------------
 * Creer un jeton et lui attribut les bons argument
 * ---------------------------------------------------
 * token	: chaine à traiter pour la création du jeton
 * stack    : pile dans laquel mettre les valeurs
 * ---------------------------------------------------
 * retourne le jeton si on a réussi a le créer.
 * NULL sinon.
 * ----------------------------------------------------
 */
s_token * lecture_token(char * token, s_cell * cell){
    s_token * jeton = create_jeton();

    //si c'est une value
    double number = strtod(token, NULL);
    if(number > 0.0){
        jeton->type = VALUE;
        jeton->value.cst = number;
    }
    //si c'est une reference
    else if((*token>='A'&& *token<='Z')  && (*(token+1)>='0'&& *(token+1)<='9') && (*(token+2)>='0'&& *(token+2)<='9')){
        jeton->type = REF;
        s_cell * ref = trouver_cell(token, cell);
        jeton->value.ref = ref;
        cell->listeCellule = list_append(ref->listeCellule, ref);
    }
    //si c'est un operateur
    else{
        jeton->type = OPERATOR;
        if(*token == 42) jeton->value.operator = &multiplication;
        else if(*token == 47) jeton->value.operator = &division;
        else if(*token == 43) jeton->value.operator = &adition;
        else if(*token == 45) jeton->value.operator = &soustraction;
        else return create_jeton();
    }

    return jeton;
}

/* ---------------------------------------------------
 * analyse la chaine de caractères associée à une cellule
 * (le contenu de la cellule)
 * ---------------------------------------------------
 * cell		: Cellule que l'on veut lire
 * ---------------------------------------------------
 * retourne la cellule avec sa valeur, sa liste de
 * jetons et sa liste de cellules remplies
 * NULL si il y a ovreflow
 * ----------------------------------------------------
 */
s_cell * lecture_cellule(s_cell * cell){
    double value;

    //si c'est une formule
    if(*(cell->saisie) == '='){
        //on met la saisie dans un tableau
        char str[80];
        strcpy(str, cell->saisie);
        //on initilaise le delimiteur et le token
        const char delim[2] = " ";
        char * token;
        //on decoupe en petit bout et on les parcours
        token = strtok(str, delim);
        token = strtok(NULL, delim);
        while(token != NULL){
            cell->listeJetons = list_append(cell->listeJetons, lecture_token(token, cell));
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

/* ---------------------------------------------------
 * evalue la valeur de la cellule a partir de sa
 * liste de token
 * ---------------------------------------------------
 * cell		: Cellule que l'on veut evaluer
 * ---------------------------------------------------
 * retourne la cellule avec la valeur egal au resultat
 * du calcul
 * ----------------------------------------------------
 */

s_cell * eval_cellule(s_cell * cell){
    if(cell->listeJetons->suivant != NULL){
        my_stack_t * stack = stack_create(20, sizeof(double));

        cell->listeJetons = list_next(cell->listeJetons);
        while(cell->listeJetons->suivant != NULL){
            s_token * jeton = cell->listeJetons->valeur;
            if(jeton->type == VALUE){
                STACK_PUSH(stack, jeton->value.cst, double);
            }else if(jeton->type == REF){
                STACK_PUSH(stack, jeton->value.ref->valeur, double);
            }else if(jeton->type == OPERATOR){
                jeton->value.operator(stack);
            }
            cell->listeJetons = list_next(cell->listeJetons);
        }

        cell->valeur = STACK_POP(stack, double);
        stack_remove(stack);
    }

    return cell;
}
