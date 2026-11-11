#include <stdio.h>
#include "ctrl_parametres.h"
#include "../../views/Vue_parametres/Vue_parametres.h"
#include "../../services/gestion_comptes/gestion_comptes.h"
#include "../../services/gestion_audio/gestion_audio.h"


void ctrl_parametres_son(Compte *actif, Compte comptes[], int nb_comptes) {
    int choix = 0;
    printf("\n");
    vue_parametres_afficher_son(actif);

    switch (choix) {
        case 1:
            actif->audio_active = 1;
            activer_son();
            printf("\n Son active.\n");
            break;
        case 2:
            actif->audio_active = 0;
            desactiver_son();
            printf("\n Son desactive.\n");
            break;
        case 0:
            return;
        default:
            printf("\n Choix invalide.\n");
            break;
    }

    sauvegarder_tous_comptes(comptes, nb_comptes);
}

void ctrl_parametres_langues(Compte *actif, Compte comptes[], int nb_comptes) {
    int choix = 0;
    printf("\n");
    vue_parametres_afficher_langues(actif);

    switch (choix) {
        case 1:
            actif->langue = 1;
            printf("\n Langue : Francais.\n");
            break;
        case 2:
            actif->langue = 2;
            printf("\n Langue : Anglais.\n");
            break;
        case 0:
            return;
        default:
            printf("\n Choix invalide.\n");
            break;
    }

    sauvegarder_tous_comptes(comptes, nb_comptes);
}
 void ctrl_parametres_chrono(Compte *actif, Compte comptes[], int nb_comptes) {
    int choix = 0;
    printf("\n");

    vue_parametres_afficher_chrono_de_reference(actif);
    if (choix == 0) return;

    if (choix == 1) {
        if (actif->chrono_reference == 30)  actif->chrono_reference = 60;
        else if (actif->chrono_reference == 60)  actif->chrono_reference = 120;
        else                                      actif->chrono_reference = 30;

        printf("\n Chrono par defaut : %ds.\n", actif->chrono_reference);
        sauvegarder_tous_comptes(comptes, nb_comptes);
    } else {
        printf("\n Choix invalide.\n");
    }
}

void ctrl_lancer_parametres(Compte *actif, Compte comptes[], int nb_comptes) {
    int continuer = 1;
    while (continuer) {
        int choix = 0;
        choix = vue_parametres_afficher(actif);

        switch (choix) {
            case 1: ctrl_parametres_son(actif, comptes, nb_comptes);    break;
            case 2: ctrl_parametres_langues(actif, comptes, nb_comptes); break;
            case 3: ctrl_parametres_chrono(actif, comptes, nb_comptes);  break;
            case 0: continuer = 0;                                       break;
            default:
                printf("\n Choix invalide.\n");
                break;
        }
    }
}
