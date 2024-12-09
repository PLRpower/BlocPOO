//
// Created by pault on 18/11/2024.
//

#include "Bathroom.h"

Bathroom::Bathroom(const int nbWindows, const string &color, const bool shower)
: Room(nbWindows, color), hasShower(shower) {}

bool Bathroom::getHasShower() const {
    return hasShower;
}

void Bathroom::setHasShower(const bool shower) {
    hasShower = shower;
}

bool Bathroom::isBathroom() {
    return true;
}