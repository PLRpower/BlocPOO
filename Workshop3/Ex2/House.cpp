#include "House.h"

#include "Room.h"
#include <iostream>

using namespace std;

House::House(const int nbOfRooms) : nbOfRooms(nbOfRooms), count(0) {
    maison = new Room*[nbOfRooms];
}

void House::getNbOfBedrooms() const {
    int nbBedrooms = 0;
    for (int i = 0; i < count; ++i) {
        if (maison[i]->isBedroom()) {
            ++nbBedrooms;
        }
    }
    cout << "Nombre de chambres : " << nbBedrooms << endl;
}

void House::getNbOfBathrooms() const {
    int nbBathrooms = 0;
    for (int i = 0; i < count; ++i) {
        if (maison[i]->isBathroom()) {
            ++nbBathrooms;
        }
    }
    cout << "Nombre de salle de bains : " << nbBathrooms << endl;
}


void House::addRoom(Room *room) {
    if (count < nbOfRooms) {
        maison[count++] = room;
    } else {
        cout << "Maison pleine" << endl;
    }
}