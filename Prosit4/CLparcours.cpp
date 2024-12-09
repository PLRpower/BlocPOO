#include "CLparcours.h"
#include <iostream>

using namespace std;

CLparcours::CLparcours(const int nbPoints, const int type) : nbPoints(nbPoints), type(type) {}

void CLparcours::ajouterPoint(CLpoint* p) {
    points.push_back(p);
}

double CLparcours::calculDistance() const {
    double distance = 0.0;
    for (int i = 1; i < nbPoints; ++i) {
        distance += points[i-1]->distance(*points[i]);
    }
    return distance;
}

void CLparcours::message() const {
    cout << "Calcul d'un parcours de type " << type << "D" << endl;
}