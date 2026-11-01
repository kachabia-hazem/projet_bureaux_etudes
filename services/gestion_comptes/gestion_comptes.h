#ifndef GESTION_COMPTES_H
#define GESTION_COMPTES_H

#include "compte.h"

int  charger_tous_comptes(Compte comptes[]);
void sauvegarder_tous_les_comptes(Compte comptes[], int nb_comptes);
int  creer_compte(Compte comptes[], int *nb_comptes, char *pseudo);
int  trouver_compte(Compte comptes[], int nb_comptes, char *pseudo);

#endif