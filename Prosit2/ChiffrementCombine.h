#ifndef CHIFFREMENTCOMBINE_H
#define CHIFFREMENTCOMBINE_H

#include "ChiffrementCesar.h"
#include "ChiffrementXOR.h"

class ChiffrementCombine final : public Chiffrement {
public:
    explicit ChiffrementCombine();
    string chiffrer(const string& texte) override;  // Redéfinition des méthodes virtuelles pures
    string dechiffrer(const string& texte) override;  // override est optionnel mais permet de vérifier que la méthode est bien une redéfinition
private:
    ChiffrementCesar chiffrementCesar;
    ChiffrementXOR chiffrementXOR;
};

#endif //CHIFFREMENTCOMBINE_H
