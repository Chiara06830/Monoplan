#include "stack.h"
#include "liste.h"

typedef struct cell{
    char * coordonnees; //(exemple B34)
    char * saisie; //saisie de l'utilisateur
    double valeur; //valeur numérique de la saisie
    int degNeg; //degrée négatif du noeud dans le graphe 
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

/* ---------------------------------------------------
 * Créer un cellule et l'ajoute a la liste des cellules
 * ---------------------------------------------------
 * saisie   : chaine de caractère entrée dans la cellule
 * coor		: coordonnées de la cellule (ex: A01)
 * ---------------------------------------------------
 * retourne une cellule avec une valeur egale a 0
 * ----------------------------------------------------
 */
s_cell * create_cellule(char * saisie, char * coor);

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
s_cell * lecture_cellule(s_cell * cell);

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
s_cell * eval_cellule(s_cell * cell);
