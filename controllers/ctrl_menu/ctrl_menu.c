#include <stdio.h>
#include "ctrl_menu.h"
#include "vue_menu_principal.h"
#include "ctrl_choix_mode.h"
#include "ctrl_scores.h"
#include "ctrl_parametres.h"

void ctrl_menu_lancer(Compte *actif, Compte comptes[], int nb_comptes) {
    int continuer = 1;
    while (continuer) {
        int choix = vue_menu_principal_afficher(actif);

        switch (choix) {
            case 1: ctrl_lancer_choix_mode(actif);    
                break;
            case 2: ctrl_lancer_scores(comptes, nb_comptes, actif); 
                break;
            case 3: ctrl_lancer_parametres(actif, comptes, nb_comptes);
                break;
            case 4: continuer = 0;                                    break;
                default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }
}