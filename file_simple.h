#ifndef FILE_SIMPLE_H
#define FILE_SIMPLE_H

// Ce fichier contient la définition d'une file simple  et les fonctions nécessaires pour manipuler cette structure.


#define TAILLE_MAX 10  // Définition de la taille maximale de la file

// Structure représentant une file (FIFO)
typedef struct {
    float file[TAILLE_MAX];
    int tete;
    int arriere;
    int taille;
} File;


void initialiser_file(File *f);
int est_vide(File *f);
int est_pleine(File *f);
void enfiler(File *f, float e);
void defiler(File *f);
float voir_tete(File *f);

#endif
