#include <stdio.h>
#include "vue_choix_mode.h"

#define CYAN   "\033[1;36m"
#define JAUNE  "\033[1;33m"
#define VERT   "\033[1;32m"
#define ROUGE  "\033[1;31m"
#define RESET  "\033[0m"

int vue_choix_mode_afficher(void) {
    int choix = 0;
    int i;

    for (i = 0; i < 30; i++) printf("\n");

    printf(CYAN "=== JEU DE MOTUS ===%s\n\n", RESET);
    printf(CYAN "=========================================\n" RESET);
    printf(CYAN "               CHOIX DU MODE             \n" RESET);
    printf(CYAN "=========================================\n\n" RESET);

    printf(JAUNE "   1." RESET " Classique\n");
    printf(JAUNE "   2." RESET " Chronometre\n");
    printf(JAUNE "   3." RESET " Normal\n");
    printf(JAUNE "   4." RESET " Duel (2 joueurs)\n");
    printf(JAUNE "   5." RESET " Configuration Perso (grille personnalisee)\n");
    printf(ROUGE "   0." RESET " Retour\n\n");

    printf(CYAN "=========================================\n" RESET);
    printf(" Votre choix : ");

    scanf("%d", &choix);     // vide le \n restant

    if (choix < 0 || choix > 5) return -1;
    return choix;
}
