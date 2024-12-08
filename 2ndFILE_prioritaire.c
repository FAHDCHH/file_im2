#include "2ndFILE_prioritaire.h"
#include <stdio.h>


FilePrioritaire creer_file_prioritaire(int p) {
    FilePrioritaire f;
    if (p > NOMBRE_MAX_PRIORITES) {
        printf("Erreur : le nombre de priorites dépasse la limite maximale.\n");
        return f;  // Retourner une FilePrioritaire non initialisée
    }
    f.p = p;  // Définir le nombre de priorités
    for (int i = 0; i < p; i++) {
        initialiser_file(&f.files[i]);  // Initialiser chaque file
    }
    return f;
}

void enfiler_prioritaire(FilePrioritaire *f, float e, int priorite) {
    if (priorite < 0 || priorite >= f->p) {
        printf("Erreur : niveau de priorite invalide.\n");
        return;
    }
    enfiler(&f->files[priorite], e);
}

void defiler_prioritaire(FilePrioritaire *f) {
    for (int i = 0; i < f->p; i++) {
        if (!est_vide(&f->files[i])) {
            defiler(&f->files[i]);
            return;
        }
    }
    printf("Erreur : toutes les files de priorite sont vides.\n");
}

float premier_prioritaire(FilePrioritaire f) {
    for (int i = 0; i < f.p; i++) {
        if (!est_vide(&f.files[i])) {
            return voir_tete(&f.files[i]);
        }
    }
    printf("Erreur : toutes les files de priorite sont vides.\n");
    return -1.0;  // Valeur d'erreur
}

int priorite_max(FilePrioritaire f) {
    for (int i = 0; i < f.p; i++) {
        if (!est_vide(&f.files[i])) {
            return i;  // Retourner l'indice de la priorite la plus haute
        }
    }
    printf("Erreur : toutes les files de priorite sont vides.\n");
    return -1;  // Valeur d'erreur
}

void afficher_toutes_les_files(FilePrioritaire f) {
    for (int i = 0; i < f.p; i++) {  // Itérer sur toutes les priorités
        printf("Priorite %d: ", i);
        if (est_vide(&f.files[i])) {
            printf("(vide)\n");
        } else {
            int taille = f.files[i].taille;
            for (int j = 0; j < taille; j++) {
                printf("%f ", f.files[i].file[(f.files[i].tete + j) % TAILLE_MAX]);
            }
            printf("\n");
        }
    }
}
