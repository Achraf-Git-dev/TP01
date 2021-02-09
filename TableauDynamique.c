#include "TableauDynamique.h"

int** CreerMatrice(FILE* fichier, int** matrice){
    int nombre_de_ligne, nombre_de_colonne, i;

    fscanf(fichier, "%d %d", &nombre_de_ligne, &nombre_de_colonne);

    matrice = malloc(nombre_de_ligne * sizeof(int*));
    for (i=0;i<nombre_de_ligne;i++){
        matrice[i] = malloc(nombre_de_colonne * sizeof(int));
    }
    return matrice;
}

void RemplirMatrice(FILE* fichier, int** matrice){
    int nombre_de_ligne, nombre_de_colonne, nombre_lu, i, j;

    fscanf(fichier, "%d %d", &nombre_de_ligne, &nombre_de_colonne);

    for (i=0;i<nombre_de_ligne;i++){
        for (j=0;j<nombre_de_colonne;j++){
            fscanf(fichier, "%d", &nombre_lu);
            matrice[i][j] = nombre_lu;
        }
    }
}

void AfficherMatrice(FILE* fichier, int** matrice){
    int nombre_de_ligne, nombre_de_colonne, i, j;

    fscanf(fichier, "%d %d", &nombre_de_ligne, &nombre_de_colonne);

    for (i=0;i<nombre_de_ligne;i++){
        for (j=0;j<nombre_de_colonne;j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int** SupprimerMatrice(FILE* fichier, int** matrice){
    int nombre_de_ligne, nombre_de_colonne, i;
    
    fscanf(fichier, "%d %d", &nombre_de_ligne, &nombre_de_colonne);

    for (i=0;i<nombre_de_ligne;i++){
        free(matrice[i]);
    }
    free(matrice);

    return matrice;
}