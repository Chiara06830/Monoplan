#include <stdio.h>

#include "cellule.h"
#include "test.h"

#define EPSILON 0.0000001f

int testCellule(){
    printf("\n//----------DEBUT TESTES MODULE CELLULE----------//\n");

    //création des cellules
    s_cell * text = create_cellule("Bonjour", "A12");
    s_cell * vide = create_cellule("", "B48");
    s_cell * nombreP = create_cellule("12.8", "D32");
    s_cell * nombreN = create_cellule("-46.78", "A01");
    s_cell * formule = create_cellule("= 3.2 5.0 + 4.0 * 8.12 / &", "J46");
    s_cell * reference = create_cellule("= D32 A01 + &", "J39");
    s_cell * refInconnu = create_cellule("= K21 S36 + &", "G04");
    s_cell * phrase = create_cellule("je suis une phrase", "Y05");
    s_cell * erreure = create_cellule("= D32 blblbl * 5 / &", "J12");

    //---------lecture simple-----------

    //lecture d'une chaine de caractère
    text = lecture_cellule(text);
    text = eval_cellule(text);
    if(text->valeur != 0.0){
        fprintf(stderr, "ERREUR lecture_cellule() \"Bonjour\" : %f au lieu de 0.0\n", text->valeur);
        return 1;
    }

    //lecture d'une chaine vide
    vide = lecture_cellule(vide);
    vide = eval_cellule(vide);
    if(vide->valeur != 0.0){
        fprintf(stderr, "ERREUR lecture cellule() \"\" : %d au lieu de 0.0\n", vide->valeur);
        return 1;
    }

    //lecture d'un double positif
    nombreP = lecture_cellule(nombreP);
    nombreP = eval_cellule(nombreP);
    if(nombreP->valeur != 12.8){
        fprintf(stderr, "ERREUR lecture_cellule() \"12.8\" : %f au lieu de 12.8\n", nombreP->valeur);
        return 1;
    }

    //lecture d'un double négatif
    nombreN = lecture_cellule(nombreN);
    nombreN = eval_cellule(nombreN);
    if(nombreN->valeur != -46.78){
        fprintf(stderr, "ERREUR lecture_cellule() \"-46.78\" : %f au lieu de -46.78\n", nombreN->valeur);
        return 1;
    }

    //---------lecture formule-----------

    //lecture d'une formule
    formule = lecture_cellule(formule);
    //pour l'instant le calcul n'est pas fait donc la valeur dit être égal a zéro
    if(formule->valeur != 0.0){
        fprintf(stderr, "ERREUR lecture_cellule() \"= 3.2 5.0 + 4.0 * 8.12 / &\" : %f au lieu de 0.0\n", formule->valeur);
        return 1;
    }
    formule = eval_cellule(formule);
    if(fabs(formule->valeur - 4.039409) < EPSILON){
        fprintf(stderr, "ERREUR lecture_cellule() \"= 3.2 5.0 + 4.0 * 8.12 / &\" : %f au lieu de 4.039409\n", formule->valeur);
        return 1;
    }

    //lecture d'une formule avec des références
    reference = lecture_cellule(reference);
    reference = eval_cellule(reference);
    if(fabs(reference->valeur - 33.98) < EPSILON){
        fprintf(stderr, "ERREUR lecture_cellule() \"= D32 A01 + &\" : %f au lieu de 33.98\n", reference->valeur);
        return 1;
    }

    //lecture d'une formule avec des références
    //qui ne font pas partie de la liste
    refInconnu = lecture_cellule(refInconnu);
    refInconnu = eval_cellule(refInconnu);
    if(refInconnu->valeur != 0.0){
        fprintf(stderr, "ERREUR lecture_cellule() \" K21 S36 + &\" : %f au lieu de 0.0\n", refInconnu->valeur);
        return 1;
    }

    //---------cas particulier-----------

    //lecture d'une cellule contenant une phrase
    phrase = lecture_cellule(phrase);
    phrase = eval_cellule(phrase);
    if(phrase->valeur != 0.0){
        fprintf(stderr, "ERREUR lecture_cellule() \"je suis une phrase\" : %f au lieu de 0.0", phrase->valeur);
        return 1;
    }

    //lecture d'une formule avec une erreure
    erreure = lecture_cellule(erreure);
    erreure = eval_cellule(erreure);
    if(erreure->valeur != 0.0){
        fprintf(stderr, "ERREUR lecture_cellule() \"= D32 blblbl * 5 / &\" : %f au lieu de 0.0", erreure->valeur);
        return 1;
    }

    printf("//-----------FIN TESTES MODULE LISTE-----------//\n\n");
    return 0;
}
