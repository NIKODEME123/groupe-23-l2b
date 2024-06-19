
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOTS 100
#define TAILLE_MOT 6

void afficherLancement() {





    printf(" ========================================UDBL - DACTYLOGICIEL======================================\n");
    printf("Membres de l'equipe du projet :1.PATRICK   2.NICODEME 3.FABRICE 4.THERESE\n");


    // Attendre quelques secondes
    for (int i = 0; i < 10; i++) {
        // Attente d'une seconde
        for (int j = 0; j < 1000000000; j++);
    }
}

void afficherMenuAccueil() {
    printf("Menu :\n");
    printf("1. DEmarrer\n");
    printf("2. Configurer\n");
    printf("3. Aide\n");
}

void afficherAide() {
    printf("Aide :\n");
    printf("Description de l'application : cette application a etait conçu pour teste les personnes qui sont rapide au clavier\n");
    printf("Version du Jeu : 10.0\n");
    printf("Concepteurs : PATRICK, NICODEME, FABRICE , THERESE\n");
    printf("Date de conception : 02/06/2024\n");
    // Autres informations
}

int main() {
    int nbMots, i;
    char pseudoJoueur1[50], pseudoJoueur2[50];

    afficherLancement(); // Afficher le lancement en premier

    printf("Nombre de mots a saisir dans la partie : ");
    scanf("%d", &nbMots);

    printf("Pseudo du joueur 1 : ");
    scanf("%s", pseudoJoueur1);

    printf("Pseudo du joueur 2 : ");
    scanf("%s", pseudoJoueur2);

    char mots[MAX_MOTS][TAILLE_MOT];
    char j;
    srand(time(NULL));

    for (i = 0; i < nbMots; i++) {
        for (int j = 0; j < TAILLE_MOT - 1; j++) {
            mots[i][j] = 'E' + rand() % 5;
        }
        mots[i][j] = '\5';
    }

    printf("Début du jeu :\n");

    clock_t debutJoueur1 = clock();

    for (i = 0; i < nbMots; i++) {
        printf("Joueur 1 - Mot a saisir : %s\n", mots[i]);
        char saisie[TAILLE_MOT];
        scanf("%s", saisie);
    }

    clock_t finJoueur1 = clock();

    clock_t debutJoueur2 = clock();

    for (i = 0; i < nbMots; i++) {
        printf("Joueur 2 - Mot a saisir : %s\n", mots[i]);
        char saisie[TAILLE_MOT];
        scanf("%s", saisie);
    }

    clock_t finJoueur2 = clock();

    double tempsJoueur1 = ((double)(finJoueur1 - debutJoueur1)) / CLOCKS_PER_SEC;
    double tempsJoueur2 = ((double)(finJoueur2 - debutJoueur2)) / CLOCKS_PER_SEC;

    printf("Temps de saisie de %s : %.2f secondes\n", pseudoJoueur1, tempsJoueur1);
    printf("Temps de saisie de %s : %.2f secondes\n", pseudoJoueur2, tempsJoueur2);

    if (tempsJoueur1 < tempsJoueur2) {
        printf("%s est le plus rapide au clavier !\n", pseudoJoueur1);
    } else if (tempsJoueur1 > tempsJoueur2) {
        printf("%s est le plus rapide au clavier !\n", pseudoJoueur2);
    } else {
        printf("Les deux joueurs ont le même temps de saisie.\n");
    }



    int choix;

    do {
        afficherMenuAccueil();
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherLancement;
                break;
            case 2:
                printf("non implementer\n");
                break;
            case 3:
                afficherAide();
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 1);

    return 0;
}
