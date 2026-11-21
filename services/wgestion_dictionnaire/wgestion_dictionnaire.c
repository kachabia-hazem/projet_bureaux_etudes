#ifndef WGESTION_DICTIONNAIRE_C_INCLUDED
#define WGESTION_DICTIONNAIRE_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "wgestion_dictionnaire.h"

void dictionnaire_tirer_mot(char *mot_choisi, int taille_max) {
    FILE *fichier = fopen("dictionnaire.txt", "r");
    if (fichier == NULL) {
        // Secours si l'executable est lance depuis bin/Debug
        fichier = fopen("../../dictionnaire.txt", "r");
    }

    // Mot par defaut si le fichier est introuvable
    strncpy(mot_choisi, "BONJOUR", (size_t)taille_max - 1);
    mot_choisi[taille_max - 1] = '\0';

    if (fichier == NULL) {
        return;
    }

    char ligne[64];
    int nb_valides = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Nettoyer les retours a la ligne (\r et \n)
        size_t len = strlen(ligne);
        while (len > 0 && (ligne[len - 1] == '\n' || ligne[len - 1] == '\r' || ligne[len - 1] == ' ')) {
            ligne[--len] = '\0';
        }

        // Garder uniquement les mots entre 5 et 10 lettres
        if ((int)len >= 5 && (int)len <= 10 && (int)len < taille_max) {
            for (size_t i = 0; i < len; i++) {
                ligne[i] = (char)toupper((unsigned char)ligne[i]);
            }
            nb_valides++;
            unsigned int alea = ((unsigned int)rand() << 15) ^ (unsigned int)rand();
            if (alea % (unsigned int)nb_valides == 0) {
                strcpy(mot_choisi, ligne);
            }
        }
    }

    fclose(fichier);
}

#endif // WGESTION_DICTIONNAIRE_C_INCLUDED
