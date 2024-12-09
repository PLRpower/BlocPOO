#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(const Point& p1, const Point& p2)
    : Polygone({p1, Point(p1.getX(), p2.getY()), p2, Point(p2.getX(), p1.getY())}),
        longueur(sommets[0].distance(sommets[1])),
        largeur(sommets[0].distance(sommets[3])) {}

float Rectangle::getPerimetre() const {
    return 2 * (longueur + largeur);
}

float Rectangle::getAire() const {
    return largeur * largeur;
}

void Rectangle::afficheInfo() const {
    cout << "Cette forme 2D est un Rectangle (herite de Polygone)." << endl;
    cout << "Sommets :" << endl;
    afficheSommets();
    cout << "Aire : " << getAire() << endl;
    cout << "Perimetre : " << getPerimetre() << endl;
}
