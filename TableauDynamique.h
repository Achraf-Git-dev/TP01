#ifndef TABLEAU__DYNAMIQUE__H
#define TABLEAU__DYNAMIQUE__H

#include <stdio.h>
#include <stdlib.h>

int** CreerMatrice(FILE* fichier, int** matrice);

void RemplirMatrice(FILE* fichier, int** matrice);

void AfficherMatrice(FILE* fichier, int** matrice);

int** SupprimerMatrice(FILE* fichier, int** matrice);

#endif