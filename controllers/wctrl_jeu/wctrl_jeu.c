#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "wctrl_jeu.h"
#include "../../services/wgestion_dictionnaire/wgestion_dictionnaire.h"

#define MAX_ESSAIS 6

// Evalue la proposition en 2 passes :
// 2 = bien place (rouge), 1 = mal place (jaune), 0 = absent
static void evaluer_mot(const char *secret, const char *prop, int etats[]) {
    int taille = (int)strlen(secret);
    char copie_secret[32];
    strcpy(copie_secret, secret);

    for (int i = 0; i < taille; i++) {
        etats[i] = 0;
    }

    // Passe 1 : lettres bien placees
    for (int i = 0; i < taille; i++) {
        if (prop[i] == copie_secret[i]) {
            etats[i] = 2;
            copie_secret[i] = '*'; // Lettre deja utilisee
        }
    }

    // Passe 2 : lettres mal placees
    for (int i = 0; i < taille; i++) {
        if (etats[i] == 2) continue;

        for (int j = 0; j < taille; j++) {
            if (prop[i] == copie_secret[j]) {
                etats[i] = 1;
                copie_secret[j] = '*'; // Lettre deja utilisee
                break;
            }
        }
    }
}

// Affiche le mot avec les couleurs Motus
static void afficher_resultat_essai(const char *prop, const int etats[]) {
    int taille = (int)strlen(prop);
    printf("   ");
    for (int i = 0; i < taille; i++) {
        if (etats[i] == 2) {
            printf("\033[1;31m %c \033[0m", prop[i]); // Rouge : bien place
        } else if (etats[i] == 1) {
            printf("\033[1;33m %c \033[0m", prop[i]); // Jaune : mal place
        } else {
            printf(" %c ", prop[i]);                // Normal : absent
        }
    }
    printf("\n");
}

void ctrl_jeu_lancer_classique(Compte *actif) {
    static int hasard_initialise = 0;
if (!hasard_initialise) {
    srand((unsigned int)time(NULL));
    hasard_initialise = 1;
}

  char mot_secret[32];
  dictionnaire_tirer_mot(mot_secret, sizeof(mot_secret));

    int taille = (int)strlen(mot_secret);
    char proposition[32];
    int etats[32];
    char indice[32];
    indice[0] = mot_secret[0];
    for (int i = 1; i < taille; i++) {
    indice[i] = '.';
    }
   indice[taille] = '\0';
    int gagne = 0;
    int essai = 1;

    printf("\n========================================\n");
    printf("          MOTUS - MODE CLASSIQUE        \n");
    printf("========================================\n");
    printf("Joueur : %s | Record : %d pts\n", actif->pseudo, actif->meilleur_score);
    printf("Trouvez le mot de %d lettres en %d essais max.\n", taille, MAX_ESSAIS);
    printf("Legende : \033[1;31mROUGE\033[0m = bien place | \033[1;33mJAUNE\033[0m = mal place\n\n");

    while (essai <= MAX_ESSAIS && !gagne) {
        printf("Mot : ");
        for (int i = 0; i < taille; i++) {
        if (indice[i] != '.') {
        printf("\033[1;31m %c \033[0m", indice[i]);
        }
        else {
        printf(" . ");
        }
      }
printf("\n");
        printf("Essai %d/%d - Votre mot : ", essai, MAX_ESSAIS);
        scanf("%31s", proposition);

        // Vider le reste de la ligne saisie
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        // Convertir en majuscules
        for (int i = 0; proposition[i] != '\0'; i++) {
            proposition[i] = (char)toupper((unsigned char)proposition[i]);
        }

        // Verifier la longueur
        if ((int)strlen(proposition) != taille) {
            printf("Erreur : le mot doit contenir exactement %d lettres.\n\n", taille);
            continue; // Ne consomme pas d'essai
        }

        evaluer_mot(mot_secret, proposition, etats);
        for (int i = 0; i < taille; i++) {
    if (etats[i] == 2) {
        indice[i] = proposition[i];
    }
}
        afficher_resultat_essai(proposition, etats);
        printf("\n");

        if (strcmp(proposition, mot_secret) == 0) {
            gagne = 1;
        } else {
            essai++;
        }
    }

    printf("========================================\n");
    if (gagne) {
        int score_partie = (MAX_ESSAIS - essai + 1) * 100;
        printf("BRAVO ! Vous avez trouve \"%s\" en %d essai(s) !\n", mot_secret, essai);
        printf("Score obtenu : %d points\n", score_partie);

        if (score_partie > actif->meilleur_score) {
            actif->meilleur_score = score_partie;
            printf("Nouveau record personnel !\n");
        }
    } else {
        printf("PERDU ! Le mot secret etait : %s\n", mot_secret);
    }
    printf("========================================\n");
    printf("Appuyez sur Entree pour revenir au menu...");
    getchar();
}
