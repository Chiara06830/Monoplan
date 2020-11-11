/****************************************************************
    Nom du fichier : testListe.c
=================================================================
    Description : test des fonctions du module "Liste"
=================================================================
    Auteur : C. Relevat
****************************************************************/

#include <stdio.h>

#include "../include/liste.h"

/*===============================================================
    Nom de la fonction : main
-----------------------------------------------------------------
    Description : verification des fonctions du module "Liste"
-----------------------------------------------------------------
    Valeur renvoyee en cas d'erreur : 1
===============================================================*/

int main(){
    printf("\n//----------DEBUT TESTES MODULE LISTE----------//\n");

    //Création du premier noeud
    node_t * head = list_create();

    //------------------Test Get et Set------------------
    //Attribution de la valeur du premier noeud
    //avec une chaine de caractère
    char * calcul = "= A1 * A2";
    list_set_data(head, calcul);
    if(list_get_data(head) != calcul){
        fprintf(stderr, " ERREURE list_get_data(node_t * node) : %s au lieu de \"= A1 * A2\"\n", list_get_data(head));
        return 1;
    }

    //avec un int
    int valeur = 1; 
    int * pValeur = &valeur;
    list_set_data(head, pValeur);
    if(list_get_data(head) != pValeur){
        fprintf(stderr, " ERREURE list_get_data(node_t * node) : %d au lieu de 1\n", list_get_data(head));
        return 1;
    }
    
    /*La liste chainé contient 1 noeud qui a la valeure :
    1*/

    //------------------Test Creation------------------
    //ajout noeud au début
    int data = 2;
    int * pData = &data;
    head = list_insert(head, pData);
    //on verifie les valeurs des deux noeuds pour les identifiers
    if(list_get_data(head) != pData || list_get_data(head->suivant) != pValeur){
        fprintf(stderr, "ERREURE list_insert(node_t * head, void * data) : %d au lieu de 2\n", list_get_data(head));
        return 1;
    }

    /*La liste chainé contient 2 noeud qui ont comme valeur respective :
    2 -> 1*/

    //ajout noeud a la fin
    int dataFin = 3;
    int * pDataFin = &dataFin;
    head = list_append(head, pDataFin);
    if(list_get_data(head->suivant->suivant) != pDataFin){
        fprintf(stderr, "ERREURE list_append(node_t * head, void * data) : %d au lieu de 3", list_get_data(head->suivant->suivant));
        return 1;
    }

    /*La liste chainé contient 3 noeud qui ont comme valeur respective :
    2 -> 1 -> 3*/

    ////------------------Suppression------------------
    //suppression du noeud qui a la valeur 1
    head = list_remove(head, pValeur);
    if(list_get_data(head) != pData || list_get_data(head->suivant) != pDataFin){
        fprintf(stderr, "ERREURE list_remove(node_t * head, void * data) : %d au lieu de 2\n", list_get_data(head));
        return 1;
    }

    /*La liste chainé contient 2 noeud qui ont comme valeur respective :
    2 -> 3*/

    //suppression du noeud en tete de liste
    head = list_headRemove(head);
    if(list_get_data(head) != pDataFin){
        fprintf(stderr, "ERREURE list_headRemove(node_t * head) : %d au lieu de 3\n", list_get_data(head));
        return 1;
    }

    /*La liste chainé contient 1 noeud qui a la valeure :
    3*/

    //destrcution de la liste
    list_destroy(head);

    /*La liste est maintenant vide*/

    printf("//-----------FIN TESTES MODULE LISTE-----------//\n\n");

    return 0;
}