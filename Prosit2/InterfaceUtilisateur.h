#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include "Chiffrement.h"

class InterfaceUtilisateur {
public:
    static int demanderCle();  // Méthode statique pour demander la clé
    static Chiffrement* demanderMethodeChiffrement();  // Méthode statique pour demander la méthode de chiffrement
    static int demanderChiffrementDechiffrement();  // Méthode statique pour demander si l'utilisateur veut chiffrer ou déchiffrer
    static string demanderFichierSource();  // Méthode statique pour demander le fichier source
    static string demanderFichierDestination();  // Méthode statique pour demander le fichier de destination
};



#endif //INTERFACEUTILISATEUR_H
