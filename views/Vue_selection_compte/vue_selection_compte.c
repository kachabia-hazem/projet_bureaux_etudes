#include<stdio.h>
#include "vue_selection_compte.h"

int afficher_vue_selection_compte(Compte comptes[], int nb_comptes) {
    int choix = 0;
    int i = 0;
    
    printf("             CHOIX DU COMPTE               \n");
    printf("*******************************************\n");

    for( i = 0; i < nb_comptes; i++) {
        printf("%d. %s\n", i + 1, comptes[i].pseudo);
    }

    printf("\n%d. Creer un nouveau compte\n", nb_comptes + 1);
    printf("0. Quitter\n");

    printf("\nVeuillez entrer votre choix : ");
    scanf("%d", &choix);
    return choix;
}
