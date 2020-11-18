#include "liste.h"
#include "stack.h"

typedef struct cell{
    char * saisie; //saisie de l'utilisateur
    double valeur; //valeur numérique de la saisie
    node_t * listeJetons; //jetons construits a partir de l'analyse de la formule
    node_t * listeCellule; //cellules dépendantes de celle ci
}s_cell;

typedef struct token {
    //Un jeton représente soit un nombre, soit une référence vers une autre
    //cellule, soit un opérateur
    enum {VALUE, REF, OPERATOR} type ;
    union {
        double cst;
        s_cell * ref;
        void (*operator)(my_stack_t * eval);
    }value ;
}s_token;

//créer la cellule
s_cell * create_cellule(char * saisie);

//analyse la chaine de caractères associée à une cellule 
//(le contenu de la cellule)
s_cell * lecture_cellule(s_cell * cell);

//évalue une cellule unique
s_cell * eval_cellule(s_cell * cell);