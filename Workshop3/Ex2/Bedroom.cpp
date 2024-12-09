#include "Bedroom.h"

Bedroom::Bedroom(const int nbWindows, const string &color, const int nbBeds)
: Room(nbWindows, color), nbBeds(nbBeds) {}

int Bedroom::getNbBeds() const {
    return nbBeds;
}

void Bedroom::setNbBeds(const int beds) {
    nbBeds = beds;
}

bool Bedroom::isBedroom() {
    return true;
}