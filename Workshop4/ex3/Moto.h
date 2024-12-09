#ifndef MOTO_H
#define MOTO_H
#include "Vehicule.h"

class Moto final : public Vehicule {
public:
    void laver() const override;
};



#endif //MOTO_H
