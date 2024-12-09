#ifndef VOITURE_H
#define VOITURE_H
#include "Vehicule.h"


class Voiture final : public Vehicule {
public:
    void laver() const override;
};



#endif //VOITURE_H
