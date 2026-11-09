#include <stdio.h>
#include <string.h>
#include "gestion_comptes.h"
#include "compte.h"

#ifndef MAX_COMPTES
#define MAX_COMPTES 100
#endif

int charger_tous_comptes(Compte comptes[]) {
    (void)comptes;
    printf("[stub] comptes charges.\n");
    return 0;
}

void sauvegarder_tous_comptes(Compte comptes[], int nb) {
    (void)comptes; (void)nb;
    printf("[stub] comptes sauvegardes.\n");
}

int creer_compte(Compte comptes[], int *nb, const char *pseudo) {
    if (*nb >= MAX_COMPTES) return -1;   // MAX_COMPTES vient du #define
    strcpy(comptes[*nb].pseudo, pseudo);
    strcpy(comptes[*nb].chemin_logo, "default.png");
    comptes[*nb].meilleur_score   = 0;
    comptes[*nb].audio_active     = 1;
    comptes[*nb].langue           = 1;
    comptes[*nb].chrono_reference = 60;
    (*nb)++;
    return 0;
}
int connexion_en_invite(Compte comptes[], int *nb) {
    if (*nb >= MAX_COMPTES) return -1;   // MAX_COMPTES vient du #define
    strcpy(comptes[*nb].pseudo, "InvitER");
    strcpy(comptes[*nb].chemin_logo, "default.png");
    comptes[*nb].meilleur_score   = 0;
    comptes[*nb].audio_active     = 1;
    comptes[*nb].langue           = 1;
    comptes[*nb].chrono_reference = 60;
    (*nb)++;
    return 0;
}

int trouver_compte(Compte comptes[], int nb, const char *pseudo) {
    int i;
    for ( i = 0; i < nb; i++)
        if (strcmp(comptes[i].pseudo, pseudo) == 0) return i;
    return -1;
}
