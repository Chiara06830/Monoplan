#include <stdlib.h>
#include <stdio.h>

#include "../include/liste.h"

//création d'une nouvelle liste vide
node_t * list_create(){
    node_t * node;
    if( (node = (node_t *)malloc(sizeof(node_t))) == NULL){
        return NULL;
    }
    //une liste vide est représenté par un pointeur NULL
    node->suivant = NULL;
    return node;
}

//lire ou écrire la donnée d'un noeud
void * list_get_data(node_t * node){
    return node->valeur;
}

void list_set_data(node_t * node, void * data){
    node->valeur = data;
}

//obtenir le noued suivant
node_t * list_next(node_t * node){
    return node->suivant;
}

//creation et insertion d'un noeud en tete de liste
//retourne la tete de liste
node_t * list_insert(node_t * head, void * data){
    node_t * node = list_create();
    node->valeur = data;
    node->suivant = head;
    return node;
}

//création et insertion d'un noeud en queue de liste
//retourne la tete de liste
node_t * list_append(node_t * head, void * data){
    node_t * node = list_create();
    node->valeur = data;
    node->suivant = NULL;

    for(node_t * n=head; n!=NULL; n=n->suivant){
        if(n->suivant==NULL){//si c'est le dernier
            n->suivant = node;
            break;
        }
    }

    return head;
}

//suppression de la première instance d'une donnée dans la liste
//retourne la tete de liste
node_t * list_remove(node_t * head, void * data){
    node_t * precedent = (node_t *)malloc(sizeof(node_t));
    for(node_t * n=head; n->suivant!=NULL; n=n->suivant){
        if(n->valeur == data){ //si on trouve la valeur
            if(n == head){//si c'est le premier élément
                head = n->suivant;
                free(n);
            }else{
                precedent->suivant = n->suivant;
                free(n);
            }
            break;
        }
        precedent = n;
    }

    return head;
}

//suppression de la tete de liste
//retourne la nouvelle tete de liste
node_t * list_headRemove(node_t * head){
    node_t * phead = head;//sauvegarde de ou se trouve l'ancien head
    head = head->suivant;
    free(phead);
    return head;
}

//destruction d'une liste
//(La libération des données n'est pas prise en charge)
void list_destroy(node_t * head){
    
}