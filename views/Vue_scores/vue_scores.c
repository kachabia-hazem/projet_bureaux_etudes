#include <stdio.h>
#include <string.h>
#include "vue_scores.h"

// Couleurs ANSI
#define CYAN   "\033[1;36m"
#define VERT   "\033[1;32m"
#define RESET  "\033[0m"

void afficher_vue_scores(Compte comptes[], int nb_comptes, Compte *actif) {
    int i = 0;

    for (i = 0; i < 30; i++) {
        printf("\n");
    }

    // En-tête du tableau
    printf(CYAN "=========================================\n" RESET);
    printf(CYAN "            MEILLEURS SCORES             \n" RESET);
    printf(CYAN "=========================================\n\n" RESET);

    printf("   Rang   Pseudo              Score\n");
    printf("   ----   ------------------  -----\n");

    // Boucle d'affichage
    for (i = 0; i < nb_comptes; i++) {
        // Ta logique inchangée pour détecter le joueur actif
        int est_actif = (strcmp(comptes[i].pseudo, actif->pseudo) == 0);

        if (est_actif) {
            // Si c'est le joueur actif, on l'affiche en vert
            printf(VERT " > %-4d   %-18s  %d (Vous)\n" RESET,
                   i + 1, comptes[i].pseudo, comptes[i].meilleur_score);
        } else {
            // Sinon, en blanc classique
            printf("   %-4d   %-18s  %d\n",
                   i + 1, comptes[i].pseudo, comptes[i].meilleur_score);
        }
    }

    // Pied de page
    printf("\n" CYAN "=========================================\n" RESET);
    printf(" Entree 0 pour revenir...");
}
