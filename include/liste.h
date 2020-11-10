/*
*Un node est un élément d'un liste chainé
    - sa valeur peut etre de n'importe quel type
    - suivant est le noeud suivant dans la liste
*/
typedef struct node{
    void * valeur;
    struct node * suivant;
} node_t;

//création d'une nouvelle liste vide
node_t * list_create();

//lire ou écrire la donnée d'un noeud
void * list_get_data(node_t * node);
void list_set_data(node_t * node, void * data);

//obtenir le noued suivant
node_t * list_next(node_t * node);

/*--------------CREATION--------------*/

//creation et insertion d'un noeud en tete de liste
//retourne la tete de liste
node_t * list_insert(node_t * head, void * data);

//création et insertion d'un noeud en queue de liste
//retourne la tete de liste
node_t * list_append(node_t * head, void * data);

/*--------------SUPRESSION--------------*/

//suppression de la première instance d'une donnée dans la liste
//retourne la tete de liste
node_t * list_remove(node_t * head, void * data);

//suppression de la tete de liste
//retourne la nouvelle tete de liste
node_t * list_headRemove(node_t * head);

//destruction d'une liste
//(La libération des données n'est pas prise en charge)
void list_destroy(node_t * head);