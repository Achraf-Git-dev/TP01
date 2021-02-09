#include "ListeChainee.h"

void CreerListeChainee(FILE* fichier, maillon_t* pointeur_de_tete){
    int nombre_de_ligne, nombre_de_colonne, nombre_d_elements, i;
    maillon_t* pointeur_de_parcours = pointeur_de_tete;
    
    fscanf(fichier, "%d %d", &nombre_de_ligne, &nombre_de_colonne);

    nombre_d_elements = nombre_de_colonne * nombre_de_ligne;

    for (i=0;i<nombre_d_elements;i++){
        pointeur_de_parcours = malloc(sizeof(maillon_t));
        pointeur_de_parcours = pointeur_de_parcours->suivant;
    }
    pointeur_de_parcours = NULL;
}

void RemplirListeChainee(FILE* fichier, int** matrice, maillon_t* pointeur_de_tete){
    int nombre_de_ligne, nombre_de_colonne, nombre_d_elements, i, j;
    maillon_t* pointeur_de_parcours = pointeur_de_tete;

    fscanf(fichier, "%d %d", &nombre_de_ligne, &nombre_de_colonne);
    
    while (pointeur_de_parcours != NULL){
        for (i=0;i<nombre_de_ligne;i++){
            for (j=0;j<nombre_de_colonne;j++){
                pointeur_de_parcours->contenu = matrice[i][j];
                pointeur_de_parcours = pointeur_de_parcours->suivant;
            }
        }
    }

    SupprimerMatrice(fichier, matrice);
}

void InsererMaillon(maillon_t* pointeur_sur_element_precedent, maillon_t* maillon_a_inserer){
    maillon_a_inserer->suivant = pointeur_sur_element_precedent->suivant;
    pointeur_sur_element_precedent->suivant = maillon_a_inserer;
}

void SupprimerMaillon(maillon_t* pointeur_de_tete, maillon_t* maillon_a_supprimer){
    maillon_t* pointeur_de_parcours = pointeur_de_tete;

    while ((pointeur_de_parcours != NULL) || (pointeur_de_parcours->suivant != maillon_a_supprimer)){
        pointeur_de_parcours = pointeur_de_parcours->suivant;
    }

    pointeur_de_parcours->suivant = maillon_a_supprimer->suivant;

    free(maillon_a_supprimer);
}

maillon_t* RechercherValeur(maillon_t* pointeur_de_tete, int valeur){
    maillon_t* pointeur_de_parcours = pointeur_de_tete;

    while ((pointeur_de_parcours != NULL) || (pointeur_de_parcours->contenu != valeur)){
        pointeur_de_parcours = pointeur_de_parcours->suivant;
    }

    return pointeur_de_parcours;
}

void AfficherListeChainee(maillon_t* pointeur_de_tete){
    maillon_t* pointeur_de_parcours = pointeur_de_tete;
    int contenu_courant;

    while (pointeur_de_parcours != NULL){
        contenu_courant = pointeur_de_parcours->contenu;
        printf("%d\n", contenu_courant);
        pointeur_de_parcours = pointeur_de_parcours->suivant;
    }
}