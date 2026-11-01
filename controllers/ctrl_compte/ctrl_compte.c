#include <stdio.h>
#include <string.h>
#include "ctrl_compte.h"
#include "vue_selection_compte.h"
#include "vue_creation_compte.h"
#include "gestion_comptes.h"

int ctrl_choix_compte(Compte comptes[], int nb_comptes) {
    int choix = afficher_vue_selection_compte(comptes, nb_comptes);

    if (choix == 0) {
        return -1; // Quitter
    } 
    else if (choix == nb_comptes + 1) {
        char pseudo[50];
        demande_pseudo_pour_creation_compte(pseudo);
        
        if (creer_compte(comptes, &nb_comptes, pseudo) == 0) {
            printf("Compte cree avec succes !\n");
            return nb_comptes - 1; // Retourne l'index du nouveau compte
        } 
        else {
            printf("Erreur lors de la creation du compte.\n");
            return -1;
        }
    } else if (choix > 0 && choix <= nb_comptes) {
        return choix - 1; 
    } 
    else {
        printf("Choix invalide.\n");
        return -1;
    }
}
