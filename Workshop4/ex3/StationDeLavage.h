
#ifndef STATIONLAVAGE_H
#define STATIONLAVAGE_H

#include <memory>
#include "Vehicule.h"

using namespace std;

class StationDeLavage {
private:
    Vehicule* parc[100];

public:
    void ajouterVehicule(Vehicule* vehicule);
    void retirerVehicule(int index);
    void laverTousLesVehicules() const;
};



#endif //STATIONLAVAGE_H
