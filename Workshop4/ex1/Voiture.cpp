#include "Voiture.h"
#include <iostream>

using namespace std;

int Voiture::nombreObjets = 0;

Voiture::Voiture() {
    initialiser(100, 1);
    nombreObjets++;
}

Voiture::Voiture(const int vmax, const int accel) {
    initialiser(vmax, accel);
    nombreObjets++;
}

Voiture::~Voiture() {
    nombreObjets--;
}

int Voiture::getNombreObjets() {
    return nombreObjets;
}

void Voiture::initialiser(const int vmax, const int accel) {
    vitesseMax = (vmax > 100) ? 100 : vmax;
    acceleration = (accel > 3) ? 3 : accel;
    vitesse = 0;
}

void Voiture::accelerer() {
    vitesse += acceleration;
    if (vitesse > vitesseMax) vitesse = vitesseMax;
    cout << "Vitesse actuelle de la voiture : " << vitesse << " km/h" << endl;
}
