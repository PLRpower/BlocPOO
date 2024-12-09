#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle() {}

Rectangle::Rectangle(const int d1, const int d2) : Objet2D(d1, d2) {}

int Rectangle::getLongueur() const {
    return dim1;
}

int Rectangle::getLargeur() const {
    return dim2;
}

int Rectangle::getPerimetre() const {
    return 2 * (dim1 + dim2);
}

int Rectangle::getAire() const {
    return dim1 * dim2;
}

void Rectangle::afficheInfo() const {
    cout << "Rectangle: longueur=" << dim1 << ", largeur=" << dim2 << endl;
}