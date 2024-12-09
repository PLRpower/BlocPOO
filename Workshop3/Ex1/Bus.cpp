#include "Bus.h"
#include <iostream>

using namespace std;

Bus::Bus() {
    seatCapacity = 10;
}

int Bus::getSeatingCapacity() const {
    return seatCapacity;
}

void Bus::setSeatingCapacity(const int capacity) {
    if(capacity < 10 || capacity > 50) {
        seatCapacity = 50;
    } else {
        seatCapacity = capacity;
    }
}

void Bus::getInfo() const {
    cout << "Il s'agit d'un bus d'une capacité de " << getSeatingCapacity()
    << " places, avec une vitesse maximale de " << getMaxSpeed()
    << " kmh et son kilométrage est de " << getMileage()
    << " km." << endl;
}