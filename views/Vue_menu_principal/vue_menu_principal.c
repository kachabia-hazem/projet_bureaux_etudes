#include<stdio.h>
#include "vue_menu_principal.h"
    
int afficher_vue_menu_principal(Compte* compte_actif){
    int choix = 0;
    
     printf("     _ _____ _   _   ____  _____   __  __  ___ _____ _   _ ____  \n");
    printf("    | | ____| | | | |  _ \\| ____| |  \\/  |/ _ \\_   _| | | / ___| \n");
    printf(" _  | |  _| | | | | | | | |  _|   | |\\/| | | | || | | | | \\___ \\ \n");
    printf("| |_| | |___| |_| | | |_| | |___  | |  | | |_| || | | |_| |___) |\n");
    printf(" \\___/|_____|\\___/  |____/|_____| |_|  |_|\\___/ |_|  \\___/|____/ \n");

    printf("Vous etes connectes en tant que : %s", compte_actif->pseudo);

    printf(" 1. Jouer\n");
    printf(" 2. Meilleurs Scores\n");
    printf(" 3. Parametres\n");
    printf(" 4. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    return choix;
}