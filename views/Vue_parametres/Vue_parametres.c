#include <stdio.h>
#include <string.h>
#include "vue_parametres.h"

#define CYAN   "\033[1;36m"
#define JAUNE  "\033[1;33m"
#define ROUGE  "\033[1;31m"
#define RESET  "\033[0m"

int vue_parametres_afficher(Compte *actif) {
    int choix = 0;
    int i = 0;
    for (i = 0; i < 30; i++) {
        printf("\n");
    }
    printf(CYAN "=========================================\n" RESET);
    printf(CYAN "               PARAMETRES                \n" RESET);
    printf(CYAN "=========================================\n\n" RESET);

    printf(JAUNE "   1. " RESET "Son\n");
    printf(JAUNE "   2. " RESET "Langues\n");
    printf(JAUNE "   3. " RESET "Chrono de reference\n");
    printf(ROUGE "   0. " RESET "Retour\n\n");

    printf(CYAN "=========================================\n" RESET);
    printf("Votre choix : ");
    scanf("%d", &choix);

    return choix;
}

int vue_parametres_afficher_son(Compte *actif) {
    int choix = 0;
    int i = 0;
    for (i = 0; i < 30; i++) {
        printf("\n");
    }
    printf(CYAN "=========================================\n" RESET);
    printf(CYAN "           PARAMETRES - SON              \n" RESET);
    printf(CYAN "=========================================\n\n" RESET);

    printf(JAUNE "   1. " RESET "Activer le son\n");
    printf(JAUNE "   2. " RESET "Desactiver le son\n");
    printf(ROUGE "   0. " RESET "Retour\n\n");

    printf(CYAN "=========================================\n" RESET);
    printf("Votre choix : ");
    scanf("%d",&choix);

    return choix;
}

int vue_parametres_afficher_Difficulte(Compte *actif) {
    int choix = 0;
    int i = 0;
    for (i = 0; i < 30; i++) {
        printf("\n");
    }
    printf(CYAN "=========================================\n" RESET);
    printf(CYAN "        PARAMETRES - DIFFICULTE          \n" RESET);
    printf(CYAN "=========================================\n\n" RESET);

    printf(JAUNE "   1. " RESET "Facile\n");
    printf(JAUNE "   2. " RESET "Normal\n");
    printf(JAUNE "   3. " RESET "Difficile\n");
    printf(ROUGE "   0. " RESET "Retour\n\n");

    printf(CYAN "=========================================\n" RESET);
    printf("Votre choix : ");
    scanf("%d",&choix);

    return choix;
}

int vue_parametres_afficher_langues(Compte *actif) {
    int choix = 0;
    int i = 0;
    for (i = 0; i < 30; i++) {
        printf("\n");
    }
    printf(CYAN "=========================================\n" RESET);
    printf(CYAN "          PARAMETRES - LANGUES           \n" RESET);
    printf(CYAN "=========================================\n\n" RESET);

    printf(JAUNE "   1. " RESET "Francais\n");
    printf(JAUNE "   2. " RESET "Anglais\n");
    printf(ROUGE "   0. " RESET "Retour\n\n");

    printf(CYAN "=========================================\n" RESET);
    printf("Votre choix : ");
    scanf("%d",&choix);

    return choix;
}

int vue_parametres_afficher_chrono_de_reference(Compte *actif) {
    int choix = 0;
    int i = 0;
    for (i = 0; i < 30; i++) {
        printf("\n");
    }
    printf(CYAN "=========================================\n" RESET);
    printf(CYAN "      PARAMETRES - CHRONO DE REFERENCE   \n" RESET);
    printf(CYAN "=========================================\n\n" RESET);

    printf(JAUNE "   1. " RESET "Modifier le chrono\n");
    printf(ROUGE "   0. " RESET "Retour\n\n");

    printf(CYAN "=========================================\n" RESET);
    printf("Votre choix : ");
    scanf("%d",&choix);

    return choix;
}
