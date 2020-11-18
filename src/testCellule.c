#include <stdio.h>

#include "../include/cellule.h"

int main(){
    printf("\n//----------DEBUT TESTES MODULE CELLULE----------//\n");

    //création des cellules
    s_cell * text = create_cellule("Bonjour");
    s_cell * vide = create_cellule("");
    s_cell * nombreP = create_cellule("12.8");
    s_cell * nombreN = create_cellule("-46.78");
    s_cell * formule = create_cellule("= 3 5+ 4* 8/");

    //------------------Test lecture------------------
    //lecture d'une chaine de caractère
    text = lecture_cellule(text);
    if(text->valeur != 0.0){
        fprintf(stderr, "ERREURE lecture_cellule() \"Bonjour\" : %d au lieu de 0.0", text->valeur);
        return 1;
    }

    //lecture d'une chaine vide
    vide = lecture_cellule(vide);
    if(vide->valeur != 0.0){
        fprintf(stderr, "ERREURE lecture cellule() \"\" : %d au lieu de 0.0", vide->valeur);
        return 1;
    }

    //lecture d'un double positif
    nombreP = lecture_cellule(nombreP);
    if(nombreP->valeur != 12.8){
        fprintf(stderr, "ERREURE lecture_cellule() \"12.8\" : %d au lieu de 12.8", nombreP->valeur);
        return 1;
    }

    //lecture d'un double négatif
    nombreN = lecture_cellule(nombreN);
    if(nombreN->valeur != -46.78){
        fprintf(stderr, "ERREURE lecture_cellule() \"-46.78\" : %d au lieu de -46.78", nombreN->valeur);
        return 1;
    }

    printf("//-----------FIN TESTES MODULE LISTE-----------//\n\n");
}