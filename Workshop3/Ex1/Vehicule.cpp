#include "Vehicule.h"

Vehicule::Vehicule() {
    maxSpeed = 240;
    mileage = 0;
}

void Vehicule::setMaxSpeed(const int speed) {
    if(speed < 200) {
        maxSpeed = 240;
    } else {
        maxSpeed = speed;
    }
}

int Vehicule::getMaxSpeed() const {
    return maxSpeed;
}

int Vehicule::getMileage() const {
    return mileage;
}

void Vehicule::setMileage(const int km) {
    if(km < 0) {
        mileage = 0;
    } else {
        mileage = km;
    }
}