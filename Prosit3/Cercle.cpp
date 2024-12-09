#include "Cercle.h"
#include <numbers>
#include <iostream>

using namespace std;

Cercle::Cercle(const Point& centre, const float rayon)
    : centre(centre), rayon(rayon) {}

float Cercle::getPerimetre() const {
    return 2 * numbers::pi * rayon;
}

float Cercle::getAire() const {
    return numbers::pi * rayon * rayon;
}

void Cercle::afficheInfo() const {
    cout << "Cette forme 2D est un Cercle." << endl;
    cout << "Centre : ";
    centre.affiche();
    cout << "Aire : " << getAire() << endl;
    cout << "Perimetre : " << getPerimetre() << endl;
}