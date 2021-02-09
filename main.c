#include "TableauDynamique.h"
#include "ListeChainee.h"

int main(){
    FILE* fic = NULL;
    int** mat;
    maillon_t* tete;

    fic = fopen("test.txt", "r");

    if (fic != NULL){
        mat = CreerMatrice(fic, mat);
        if (mat != NULL){
            rewind(fic);
            RemplirMatrice(fic, mat);
            rewind(fic);
            AfficherMatrice(fic, mat);
            rewind(fic);
            CreerListeChainee(fic, tete);
            if (tete != NULL){
                rewind(fic);
                RemplirListeChainee(fic, mat, tete);
                AfficherListeChainee(tete);
                printf("verification de supp de matrice : %d", **mat);
            }
            else printf("FUCK IT\n");
        }
        else printf("FUCK IT\n");
    }

    return 0;
}