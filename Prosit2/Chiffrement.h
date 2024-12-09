#ifndef CHIFFREMENT_H
#define CHIFFREMENT_H

#include <string>
#include <iostream>

using namespace std;

class Chiffrement {
public:
    virtual string chiffrer(const string& texte) = 0;  // Méthodes virtuelles pures, doivent être redéfinies dans les classes filles
    virtual string dechiffrer(const string& texte) = 0;

    virtual ~Chiffrement() = default;  // Destructeur virtuel obligatoire pour les classes abstraites
};

#endif //CHIFFREMENT_H
