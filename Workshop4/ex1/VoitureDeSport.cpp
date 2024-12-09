#include "VoitureDeSport.h"
#include <iostream>

using namespace std;

VoitureDeSport::VoitureDeSport() {
    vitesseMax = 200;
    acceleration = 4;
}

VoitureDeSport::VoitureDeSport(const int vmax, const int accel) : Voiture(vmax, accel) {
    vitesseMax = (vmax > 200) ? 200 : vmax;
    acceleration = (accel > 8) ? 8 : accel;
}

void VoitureDeSport::accelerer() {
    vitesse += acceleration;
    if (vitesse > vitesseMax) vitesse = vitesseMax;
    cout << "Vitesse actuelle de la voiture de sport : " << vitesse << " km/h" << endl;
}
