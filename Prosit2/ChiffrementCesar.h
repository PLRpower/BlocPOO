#ifndef CHIFFREMENTCESAR_H
#define CHIFFREMENTCESAR_H

#include "Chiffrement.h"

class ChiffrementCesar final : public Chiffrement {
public:
    explicit ChiffrementCesar();  // Constructeur par défaut

    string chiffrer(const string& texte) override;  // Redéfinition des méthodes virtuelles pures
    string dechiffrer(const string& texte) override;  // override est optionnel mais permet de vérifier que la méthode est bien une redéfinition
private:
    int decalage;
};

#endif //CHIFFREMENTCESAR_H
