#include <iostream>
#include <fstream>
#include <sstream>
#include "Fichiers.h"

string Fichiers::lireFichier(const string& nomFichier) {
    const string fichier("/home/plr/CLionProjects/Prosit2/fichiers/" + nomFichier);  // Chemin du fichier
    ifstream flux(fichier.c_str());  // Ouvre le fichier

    if(flux) {  // Si le fichier est ouvert
        stringstream buffer;  // Buffer pour stocker le contenu du fichier
        buffer << flux.rdbuf();  // Stocke le contenu du fichier dans le buffer
        return buffer.str();  // Retourne le contenu du fichier
    }
    cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    return "";
}

void Fichiers::ecrireFichier(const string& nomFichier, const string& texte) {
    const string fichier("/home/plr/CLionProjects/Prosit2/fichiers/" + nomFichier);  // Chemin du fichier
    ofstream flux(fichier.c_str());  // Ouvre le fichier
    flux << texte;  // Écrit le texte dans le fichier
    flux.close();
}
