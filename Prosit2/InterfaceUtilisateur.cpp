#include "InterfaceUtilisateur.h"
#include "ChiffrementCesar.h"
#include "ChiffrementXOR.h"
#include "ChiffrementCombine.h"

string InterfaceUtilisateur::demanderFichierSource() {
    string nomFichier;
    cout << "Entrez le nom du fichier source :\n";
    cin >> nomFichier;  // Demander à l'utilisateur de rentrer le nom du fichier
    return nomFichier;
}

string InterfaceUtilisateur::demanderFichierDestination() {
    string nomFichier;
    cout << "Entrez le nom du fichier souhaite en sortie :\n";
    cin >> nomFichier;  // Demander à l'utilisateur de rentrer le nom du fichier
    return nomFichier;
}

Chiffrement* InterfaceUtilisateur::demanderMethodeChiffrement() {
    int niveau;
    cout << "Choissisez la methode de chiffrement (1: Cesar, 2: XOR, 3: Les deux) :\n";
    cin >> niveau;  // Demander à l'utilisateur de choisir
    while (niveau < 1 || niveau > 3) {  // Vérifie que le choix est valide
        cerr << "Erreur, veuillez selectionner une methode de chiffrement valide (1: Cesar, 2: XOR, 3: Les deux) :\n";
        cin >> niveau;  // Redemander à l'utilisateur de choisir
    }
    if(niveau == 1) { return new ChiffrementCesar(); }  // Retourne un objet de la classe correspondante
    if(niveau == 2) { return new ChiffrementXOR(); }
    return new ChiffrementCombine();
}

int InterfaceUtilisateur::demanderChiffrementDechiffrement() {
    int fonction;
    cout << "Voulez vous chiffrer ou dechiffrer un fichier (1: Chiffrer, 2: Dechiffrer) :\n";
    cin >> fonction;  // Demander à l'utilisateur de choisir
    while (fonction < 1 || fonction > 2) {  // Vérifie que le choix est valide
        cerr << "Erreur, veuillez selectionner une fonction valide (1: Chiffrer, 2: Dechiffrer) :\n";
        cin >> fonction;  // Redemander à l'utilisateur de choisir
    }
    return fonction;
}