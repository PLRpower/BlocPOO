#include "ChiffrementXOR.h"

ChiffrementXOR::ChiffrementXOR() {
    cout << "Choissisez la cle pour le chiffrement XOR :\n";
    cin >> cle;  // Demande à l'utilisateur de choisir la clé
}

string ChiffrementXOR::chiffrer(const string& texte) {
    string resultat;

    for (const char c : texte) {  // Parcours chaque caractère du texte
        resultat += static_cast<char>(c ^ cle);  // Utilisez '^' pour le XOR
    }

    return resultat;
}

string ChiffrementXOR::dechiffrer(const string& texte) {
    return chiffrer(texte);  // XOR est symétrique
}