#include "StationDeLavage.h"

void StationDeLavage::ajouterVehicule(Vehicule* vehicule) {
    for (auto & i : parc) {
        if (i == nullptr) {
            i = vehicule;
            break;
        }
    }
}

void StationDeLavage::retirerVehicule(const int index) {
    parc[index] = nullptr;
}

void StationDeLavage::laverTousLesVehicules() const {
    for (const auto i : parc) {
        if (i != nullptr) {
            i->laver();
        }
    }
}