#include <stdio.h>
#include <string.h>
#include "vue_parametres.h"

int vue_parametres_afficher(Compte *actif) {
    int choix = 0;
     printf("           PARAMETRES                    \n");
    printf("=========================================\n\n");
    printf("   1. Son\n");
    printf("   2. Langues\n");
    printf("   3. Chrono de référence\n");
    printf("   0. Retour\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void vue_parametres_afficher_son(Compte *actif) {
    printf("           PARAMETRES - SON              \n");
    printf("=========================================\n\n");
    printf("   1. Activer le son\n");
    printf("   2. Desactiver le son\n");
    printf("   0. Retour\n");
    printf("Votre choix : ");
}

void vue_parametres_afficher_langues(Compte *actif) {
    printf("           PARAMETRES - LANGUES          \n");
    printf("=========================================\n\n");
    printf("   1. Francais\n");
    printf("   2. Anglais\n");
    printf("   0. Retour\n");
    printf("Votre choix : ");
}

void vue_parametres_afficher_chrono_de_reference(Compte *actif) {
    printf("           PARAMETRES - CHRONO DE RÉFÉRENCE     \n");
    printf("=========================================\n\n");
    printf("   1. Modifier le chrono\n");
    printf("   0. Retour\n");
    printf("Votre choix : ");
}
