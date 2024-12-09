#ifndef VOITUREDESPORT_H
#define VOITUREDESPORT_H

#include "Voiture.h"

class VoitureDeSport final : public Voiture {
public:
    VoitureDeSport();
    VoitureDeSport(int vmax, int accel);

    void accelerer() override;
};

#endif // VOITUREDESPORT_H
