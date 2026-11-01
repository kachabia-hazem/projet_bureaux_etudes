#ifndef COMPTE_H
#define COMPTE_H

typedef struct Compte {
    char pseudo[50];
    int meilleur_score;
    int audio_active;              
    int langue;                    
    int chrono_reference;
} Compte;

#endif 
