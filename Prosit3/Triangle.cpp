#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
    : Polygone({p1, p2, p3}),
    longueur1(sommets[0].distance(sommets[1])),
    longueur2(sommets[1].distance(sommets[2])),
    longueur3(sommets[2].distance(sommets[0])) {}

float Triangle::getPerimetre() const {
    return longueur1 + longueur2 + longueur3;
}

float Triangle::getAire() const {
    // Formule de Héron (https://fr.wikipedia.org/wiki/Formule_de_H%C3%A9ron)
    const float p = (longueur1 + longueur2 + longueur3) / 2;
    return sqrt(p * (p - longueur1) * (p - longueur2) * (p - longueur3));
}

void Triangle::afficheInfo() const {
    cout << "Cette forme 2D est un Triangle (herite de Polygone)." << endl;
    cout << "Sommets : " << endl;
    afficheSommets();
    cout << "Perimetre : " << getPerimetre() << endl;
    cout << "Aire : " << getAire() << endl;
}