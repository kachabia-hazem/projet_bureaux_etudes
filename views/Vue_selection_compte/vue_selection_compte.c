#include <stdio.h>
#include "vue_selection_compte.h"

// Couleurs ANSI
#define CYAN   "\033[1;36m"
#define JAUNE  "\033[1;33m"
#define VERT   "\033[1;32m"
#define ROUGE  "\033[1;31m"
#define RESET  "\033[0m"

int afficher_vue_selection_compte(Compte comptes[], int nb_comptes) {
    int choix = 0;
    int i = 0;

    for (i = 0; i < 30; i++) {
        printf("\n");
    }

    // En-tête
    printf(CYAN "==============================================\n" RESET);
    printf(CYAN "              CHOIX DU COMPTE                 \n" RESET);
    printf(CYAN "==============================================\n\n" RESET);

    // Liste des comptes existants
    for( i = 0; i < nb_comptes; i++) {
        printf(JAUNE " %d. " RESET "%s\n", i + 1, comptes[i].pseudo);
    }

    // Options
    printf("\n" VERT " %d. " RESET "Creer un nouveau compte\n", nb_comptes + 1);
    printf(VERT " %d. " RESET "Connectez vous en tant qu'invite\n", nb_comptes + 2);
    printf("\n" ROUGE " 0. " RESET "Quitter\n\n");

    printf(CYAN "==============================================\n" RESET);
    printf("Veuillez entrer votre choix : ");
    scanf("%d", &choix);

    return choix;
}
