#ifndef CHIFFREMENTXOR_H
#define CHIFFREMENTXOR_H

#include "Chiffrement.h"

class ChiffrementXOR final : public Chiffrement {
public:
    explicit ChiffrementXOR();
    string chiffrer(const string& texte) override;  // Redéfinition des méthodes virtuelles pures
    string dechiffrer(const string& texte) override;  // override est optionnel mais permet de vérifier que la méthode est bien une redéfinition
private:
    int cle;
};



#endif //CHIFFREMENTXOR_H
