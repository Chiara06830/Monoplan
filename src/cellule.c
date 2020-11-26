#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "../include/cellule.h"

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

    cell->coordonnees = coor;
    cell->saisie = saisie;
    cell->valeur = 0.0;
    cell ->listeJetons = list_create();
    cell ->listeCellule = list_create();

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
            listCellules = list_insert(listCellules, cell);
            return cell;
        }
    }

    return create_cellule("", coor);
}

/* ---------------------------------------------------
 * multiplie les valeurs dans la pile
 * ---------------------------------------------------
 * coor		: coordonnées de la cellule (ex: A01)
 * ---------------------------------------------------
 */
void multiplication(my_stack_t *stack){
    double total = 1;
    while(!STACK_EMPTY(stack)){
        total *= STACK_POP(stack, double);
    }
    STACK_PUSH(stack , total, double);
}

void division(my_stack_t *stack){
    double total = STACK_POP(stack, double);
    while(!STACK_EMPTY(stack)){
        double valeur = STACK_POP(stack, double);
        if(fabs(valeur, 0.0) > 0.00001)
            total /= valeur;
    }
    STACK_PUSH(stack , total, double);
}

void adition(my_stack_t *stack){
    double total = 0;
    while(!STACK_EMPTY(stack)){
        total += STACK_POP(stack, double);
    }
    STACK_PUSH(stack , total, double);
}

void soustraction(my_stack_t *stack){
    double total = 0;
    while(!STACK_EMPTY(stack)){
        total -= STACK_POP(stack, double);
    }
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
    my_stack_t * stack = stack_create(20, sizeof(double));

    //si c'est une value
    double number = strtod(token, NULL);
    if(number > 0.0){
        jeton->type = VALUE;
        jeton->value.cst = number;
        STACK_PUSH(stack, number, double);
    }
    //si c'est une reference
    else if((*token>='A'&& *token<='Z')  && (*(token+1)>='0'&& *(token+1)<='9') && (*(token+2)>='0'&& *(token+2)<='9')){
        jeton->type = REF;
        s_cell * ref = trouver_cell(token, cell);
        jeton->value.ref = ref;
        STACK_PUSH(stack, ref->valeur, double);
    }
    //si c'est un operateur
    else if(strcmp(token, "*") || strcmp(token, "/") || strcmp(token, "+") || strcmp(token, "-")){
        jeton->type = OPERATOR;
        if(strcmp(token, "*")) jeton->value.operator = &multiplication;
        else if(strcmp(token, "/")) jeton->value.operator = &division;
        else if(strcmp(token, "+")) jeton->value.operator = &adition;
        else if(strcmp(token, "-")) jeton->value.operator = &soustraction;
    }else {
        return NULL;
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
        while(token != NULL){
            printf("%s\n", token);
            cell->listeJetons = list_insert(cell->listeJetons, lecture_token(token, cell));
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

s_cell * eval_cellule(s_cell cell){

}
