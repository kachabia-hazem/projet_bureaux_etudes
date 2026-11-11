#include<stdio.h>
#include "ctrl_choix_mode.h"
#include "../../views/Vue_choix_mode/vue_choix_mode.h"
#include "../../models/compte.h"

void ctrl_lancer_choix_mode(Compte *actif) {
    int choix = vue_choix_mode_afficher();

    switch (choix) {
        case 1:
            printf("Mode Classique selectionne.\n");
            break;
        case 2:
            printf("Mode Chronometre selectionne.\n");
            break;
        case 3:
            printf("Mode Normal selectionne.\n");
            break;
        case 4:
            printf("Mode Duel (2 joueurs) selectionne.\n");
            break;
        case 5:
            printf("Configuration Perso (grille personnalisee) selectionnee.\n");
            break;
        case 0:
            printf("Retour au menu precedent.\n");
            break;
        default:
            printf("Choix invalide. Veuillez reessayer.\n");
            break;
    }
}
