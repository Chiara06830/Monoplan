#include <stdio.h>
#include "../include/liste.h"

int main(){
    //Création du premier noeud
    node_t * head = list_create();

    //------------------Test Get et Set------------------
    //avec un int
    int valeur = 1; 
    int * pValeur = &valeur;
    list_set_data(head, pValeur);
    if(list_get_data(head) != pValeur){
        printf(" ERREURE : %d au lieu de 1", list_get_data(head));
        return 1;
    }
    //avec une chaine de caractère
    char * calcul = "= A1 * A2";
    list_set_data(head, calcul);
    if(list_get_data(head) != calcul){
        printf(" ERREURE : %s au lieu de \"= A1 * A2\"", list_get_data(head));
        return 1;
    }

    //------------------Test Creation------------------
    //ajout noeud au début
    int data = 2;
    int * pData = &data;
    head = list_insert(head, pData);
    if(list_get_data(head) != pData && list_get_data(head->suivant) != pValeur){
        printf("ERREURE : %d au lieu de 2", list_get_data(head));
        return 1;
    }

    //ajout noeud a la fin
    int dataFin = 3;
    int * pDataFin = &dataFin;
    head = list_append(head, pDataFin);
    /*if(list_get_data(head->suivant->suivant->suivant->valeur) != pDataFin){
        printf("ERREURE : %d au lieu de 3", list_get_data(head->suivant->suivant->valeur));
        return 1;
    }*/

    printf("%p\t%p\t%p\t%p\n", head, head->suivant, head->suivant->suivant, head->suivant->suivant->suivant);

    ////------------------Suppression------------------
    head = list_remove(head, pData);
    printf("\n%p\t%p\t%p\n", head, head->suivant, head->suivant->suivant);

    return 0;
}