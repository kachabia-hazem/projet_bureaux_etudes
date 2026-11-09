#include <stdio.h>
#include <string.h>

#include "models/compte.h"

#include "services\gestion_comptes\gestion_comptes.h"
#include "services\gestion_audio\gestion_audio.h"

#include "controllers/ctrl_compte/ctrl_compte.h"
#include "controllers/ctrl_menu/ctrl_menu.h"

#define MAX_COMPTES 100

int main(void) {
    Compte comptes[MAX_COMPTES];
    int nb_comptes = 0;

    // ÉTAPE 2 : Sélectionner ou créer un compte

    int index = ctrl_choix_compte(comptes, nb_comptes);

    if (index == -1) {
        printf("Aucun compte selectionne. Fermeture du programme.\n");
        return 0;
    }

    Compte *actif = &comptes[index];

    // ÉTAPE 3 : Menu principal
    ctrl_menu_lancer(actif, comptes, nb_comptes);
    printf("\nMerci d'avoir joue, %s !\n", actif->pseudo);
    return 0;
}
