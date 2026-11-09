#ifndef COMPTE_H
#define COMPTE_H

// --- CONSTANTES ---
#define MAX_COMPTES 100
#define TAILLE_PSEUDO 32
#define TAILLE_LOGO 128

// Modes de jeu (pour la suite)
#define MODE_CLASSIQUE 1
#define MODE_CHRONO    2
#define MODE_NORMAL    3
#define MODE_DUEL      4
#define MODE_PERSO     5

// --- STRUCTURE ---
typedef struct {
    char pseudo[TAILLE_PSEUDO];
    char chemin_logo[TAILLE_LOGO];
    int meilleur_score;
    int audio_active;
    int langue;
    int chrono_reference;
} Compte;

#endif
