#include "file_simple.h"
#include <stdio.h>

void initialiser_file(File *f) {
    f->tete = 0;
    f->arriere = -1;
    f->taille = 0;
}

int est_vide(File *f) {
    return f->taille == 0;
}

int est_pleine(File *f) {
    return f->taille == TAILLE_MAX;
}

void enfiler(File *f, float e) {
    if (est_pleine(f)) {
        printf("Erreur : la file est pleine.\n");
        return;
    }
    f->arriere = (f->arriere + 1) % TAILLE_MAX;  // Incrémentation circulaire
    f->file[f->arriere] = e;
    f->taille++;
}

void defiler(File *f) {
    if (est_vide(f)) {
        printf("Erreur : la file est vide.\n");
        return;
    }
    f->tete = (f->tete + 1) % TAILLE_MAX;
    f->taille--;
}

float voir_tete(File *f) {
    if (est_vide(f)) {
        return -1.0;  // Valeur d'erreur
    }
    return f->file[f->tete];
}
