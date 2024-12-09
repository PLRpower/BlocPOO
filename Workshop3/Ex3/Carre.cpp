#include "Carre.h"
#include <iostream>

using namespace std;

Carre::Carre() {}

Carre::Carre(const int cote) : Objet2D(cote, cote) {}

int Carre::getCote() const {
    return dim1;
}

int Carre::getPerimetre() const {
    return 4 * dim1;
}

int Carre::getAire() const {
    return dim1 * dim1;
}

void Carre::afficheInfo() const {
    cout << "Carre: cote=" << dim1 << endl;
}