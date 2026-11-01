#include <stdio.h>
#include "vue_choix_mode.h"
#include "compte.h"

int vue_choix_mode_afficher(void) {
    int choix = 0;
    printf("========================================\n");
    printf("|********CHOIX DU MODE DE JEU**********|   \n");
    printf("========================================\n\n");
    printf("   1. Classique\n");
    printf("   2. Chronometre\n");
    printf("   3. Normal\n");
    printf("   4. Duel  (2 joueurs)\n");
    printf("   5. Configuration Perso (grille personnalisee)\n");
    printf("   0. Retour\n\n");
    printf("=========================================\n\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}
