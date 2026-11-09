#include <stdio.h>
#include "vue_menu_principal.h"

// Couleurs ANSI
#define CYAN   "\033[1;36m"
#define JAUNE  "\033[1;33m"
#define ROUGE  "\033[1;31m"
#define RESET  "\033[0m"

int afficher_vue_menu_principal(Compte *actif) {
    int choix = 0;
    int i = 0;

    for (i = 0; i < 30; i++) {
        printf("\n");
    }

    printf(CYAN);
    printf("     _ _____ _   _   ____  _____   __  __  ___ _____ _   _ ____  \n");
    printf("    | | ____| | | | |  _ \\| ____| |  \\/  |/ _ \\_   _| | | / ___| \n");
    printf(" _  | |  _| | | | | | | | |  _|   | |\\/| | | | || | | | | \\___ \\ \n");
    printf("| |_| | |___| |_| | | |_| | |___  | |  | | |_| || | | |_| |___) |\n");
    printf(" \\___/|_____|\\___/  |____/|_____| |_|  |_|\\___/ |_|  \\___/|____/ \n");
    printf(RESET "\n");

    printf(CYAN "=========================================\n" RESET);
    printf("Vous etes connectes en tant que : " JAUNE "%s\n" RESET, actif->pseudo);
    printf(CYAN "=========================================\n\n" RESET);

    // Menu
    printf(JAUNE "   1. " RESET "Jouer\n");
    printf(JAUNE "   2. " RESET "Meilleurs Scores\n");
    printf(JAUNE "   3. " RESET "Parametres\n");
    printf(ROUGE "   4. " RESET "Quitter\n\n");

    printf("Votre choix : ");
    scanf("%d", &choix);

    return choix;
}
