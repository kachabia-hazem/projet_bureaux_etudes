#include <stdio.h>
#include "vue_creation_compte.h"

// Couleurs ANSI
#define CYAN   "\033[1;36m"
#define RESET  "\033[0m"

void demande_pseudo_pour_creation_compte(char pseudo[]) {
    int i = 0;
    for (i = 0; i < 30; i++) {
        printf("\n");
    }

    printf(CYAN "=========================================\n" RESET);
    printf(CYAN "        CREATION D'UN COMPTE             \n" RESET);
    printf(CYAN "=========================================\n\n" RESET);

    printf("Entrez votre nom de joueur : ");

    scanf("%49s", pseudo);
}
