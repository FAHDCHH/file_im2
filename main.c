#include <stdio.h>
#include "2ndFILE_prioritaire.h"



int main() {
    FilePrioritaire ma_file = creer_file_prioritaire(5);
    enfiler_prioritaire(&ma_file, 10.5, 0);
    enfiler_prioritaire(&ma_file, 20.0, 2);
    enfiler_prioritaire(&ma_file, 5.0, 1);
    enfiler_prioritaire(&ma_file, 30.0, 4);
    enfiler_prioritaire(&ma_file, 15.0, 0);

    printf("Affichage de toutes les files (priorite 0 à 4) :\n");
    afficher_toutes_les_files(ma_file);

    printf("\nPremier element prioritaire : %.2f\n", premier_prioritaire(ma_file));
    defiler_prioritaire(&ma_file);

    printf("\nAffichage apres retrait du premier element prioritaire :\n");
    afficher_toutes_les_files(ma_file);

    int priorite_maximale = priorite_max(ma_file);
    if (priorite_maximale != -1) {
        printf("\nLa priorite maximale non vide est : %d\n", priorite_maximale);
    }
    return 0;
}

