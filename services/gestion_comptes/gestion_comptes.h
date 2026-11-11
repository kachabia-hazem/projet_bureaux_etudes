#ifndef GESTION_COMPTES_H
#define GESTION_COMPTES_H

#include "../../models/compte.h"

int  charger_tous_comptes(Compte comptes[]);
void sauvegarder_tous_comptes(Compte comptes[], int nb);
int creer_compte(Compte comptes[], int *nb_comptes, const char *pseudo);
int connexion_en_invite(Compte comptes[], int *nb_comptes);
int  trouver_compte(Compte comptes[], int nb_comptes, const char *pseudo);

#endif
