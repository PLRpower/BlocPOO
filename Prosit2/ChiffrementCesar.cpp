#include "ChiffrementCesar.h"

ChiffrementCesar::ChiffrementCesar() {
    cout << "Choissisez le decalage pour le chiffrement de Cesar (1-26) :\n";
    cin >> decalage;  // On demande à l'utilisateur de choisir un décalage
    while(decalage < 1 || decalage > 26) {  // On vérifie que le décalage est valide
        cerr << "Erreur, veuillez selectionner un decalage valide (1-26) :\n";
        cin >> decalage;  // On redemande à l'utilisateur de choisir un décalage
    }
    this->decalage = decalage;
}

string ChiffrementCesar::chiffrer(const string& texte) {
    string resultat;

    for (const char c : texte) {  // On parcourt chaque caractère du texte
        if (isalpha(c)) {  // Si le caractère est une lettre
            const char base = isupper(c) ? 'A' : 'a';  // On détermine la base ('A' ou 'a')
            resultat += static_cast<char>((c - base + decalage) % 26 + base);  // On chiffre le caractère à partir de la table ASCII
        } else {
            resultat += c;  // Sinon, on ajoute le caractère tel quel
        }
    }

    return resultat;
}

string ChiffrementCesar::dechiffrer(const string& texte) {
    decalage = 26 - decalage;  // On décale de 26 - decalage pour déchiffrer
    return chiffrer(texte);
}
