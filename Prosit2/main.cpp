#include "Fichiers.h"
#include "InterfaceUtilisateur.h"

int main() {
    // Obtenir le nom du fichier source
    const string fichierSource = InterfaceUtilisateur::demanderFichierSource();

    // Obtenir le nom du fichier destination
    const string fichierDestination = InterfaceUtilisateur::demanderFichierDestination();

    // Obtenir la fonction souhaitée (1 : chiffrer, 2 : déchiffrer)
    const int fonction = InterfaceUtilisateur::demanderChiffrementDechiffrement();

    // Obtenir la méthode de chiffrement souhaitée (1 : Cesar, 2 : XOR, 3 : les deux)
    Chiffrement* methode = InterfaceUtilisateur::demanderMethodeChiffrement();

    // Lire le fichier source
    const string texte = Fichiers::lireFichier(fichierSource);

    // Chiffrer ou déchiffrer le texte en fonction de la fonction souhaitée
    string resultat;
    if(fonction == 1) {
        resultat = methode->chiffrer(texte);
    } else {
        resultat = methode->dechiffrer(texte);
    }

    // Écrire le résultat dans le fichier destination
    Fichiers::ecrireFichier(fichierDestination, resultat);

    return 0;
}
