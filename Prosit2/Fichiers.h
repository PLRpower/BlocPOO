#ifndef FICHIERS_H
#define FICHIERS_H

#include <string>

using namespace std;

class Fichiers {
public:
    static string lireFichier(const string& nomFichier);  // Méthode statique pour lire un fichier
    static void ecrireFichier(const string& nomFichier, const string& texte);  // Méthode statique pour écrire dans un fichier
};

#endif //FICHIERS_H
