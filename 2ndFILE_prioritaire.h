#ifndef FILE_PRIORITAIRE_H
#define FILE_PRIORITAIRE_H

#include "file_simple.h"

// Ce fichier définit une file prioritaire, qui est une structure de données permettant de gérer plusieurs files simples
// en fonction de priorités. Chaque file correspond à un niveau de priorité, et les éléments sont retirés en priorité
// selon leur niveau.

#define NOMBRE_MAX_PRIORITES 10  // Définition du nombre maximal de priorités


typedef struct {
    File files[NOMBRE_MAX_PRIORITES];
    int p;  // Nombre de niveaux de priorité
} FilePrioritaire;


FilePrioritaire creer_file_prioritaire(int p);
void enfiler_prioritaire(FilePrioritaire *f, float e, int priorite);
void defiler_prioritaire(FilePrioritaire *f);
float premier_prioritaire(FilePrioritaire f);
int priorite_max(FilePrioritaire f);
void afficher_toutes_les_files(FilePrioritaire f);

#endif
