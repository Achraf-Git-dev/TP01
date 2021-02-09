#ifndef LISTE__CHAINEE__H
#define LISTE__CHAINEE__H

#include <stdio.h>
#include <stdlib.h>
#include "TableauDynamique.h"

typedef struct maillon {
    int contenu;
    struct maillon *suivant;
} maillon_t;

void CreerListeChainee(FILE* fichier, maillon_t* pointeur_de_tete);

void RemplirListeChainee(FILE* fichier, int** matrice, maillon_t* pointeur_de_tete);

void InsererMaillon(maillon_t* pointeur_sur_element_precedent, maillon_t* maillon_a_inserer);

void SupprimerMaillon(maillon_t* pointeur_de_tete, maillon_t* maillon_a_supprimer);

maillon_t* RechercherValeur(maillon_t* pointeur_de_tete, int valeur);

void AfficherListeChainee(maillon_t* pointeur_de_tete);

#endif