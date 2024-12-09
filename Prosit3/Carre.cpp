#include "Carre.h"
#include <iostream>

Carre::Carre(const Point& p1, const float cote)
    : Rectangle(p1, Point(p1.getX() + cote, p1.getY() + cote)) {}

void Carre::afficheInfo() const {
    cout << "Cette forme 2D est un Carre (herite de Rectangle et donc de Polygone)." << endl;
    cout << "Sommets :" << endl;
    afficheSommets();
    cout << "Aire : " << getAire() << endl;
    cout << "Perimetre : " << getPerimetre() << endl;
}