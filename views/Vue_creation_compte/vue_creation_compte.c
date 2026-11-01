#include<stdio.h>
#include "vue_creation_compte.h"

void demande_pseudo_pour_creation_compte(char *pseudo[]) {
    printf("        CREATION D'UN COMPTE             \n");
    printf("======================================\n\n");
    printf("Entrez votre nom de joueur : ");
    scanf("%49s", pseudo);
}
