// vue_scores.c
#include <stdio.h>
#include "vue_scores.h"

void afficher_vue_scores(Compte comptes[], int nb_comptes, Compte *actif) {
    int i = 0;

    printf("          MEILLEURS SCORES               \n");
    printf("=========================================\n\n");
    printf("   Rang  Pseudo            Score\n");

    for (i = 0; i < nb_comptes; i++) {
        const char *prefix = (strcmp(comptes[i].pseudo, actif->pseudo) == 0)
                             ? " > " : "   ";
        printf("%s%-5d %-16s  %d\n",
               prefix, i + 1, comptes[i].pseudo, comptes[i].meilleur_score);
    }
    printf("\n Entree 0 pour revenir...");
    
}