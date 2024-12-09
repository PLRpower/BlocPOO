#include "Room.h"

Room::Room(const int nbWindows, const string &color) : nbWindows(nbWindows), color(color) {}

int Room::getNbWindows() const {
    return nbWindows;
}

void Room::setNbWindows(const int windows) {
    nbWindows = windows;
}

string Room::getColor() const {
    return color;
}

void Room::setColor(const string &color) {
    this->color = color;
}

bool Room::isBedroom() {
    return false;
}

bool Room::isBathroom() {
    return false;
}