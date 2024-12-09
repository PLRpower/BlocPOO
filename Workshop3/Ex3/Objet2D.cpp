#include "Objet2D.h"
#include <iostream>

using namespace std;

Objet2D::Objet2D() : dim1(0), dim2(0) {}

Objet2D::Objet2D(int d1, int d2) : dim1(d1), dim2(d2) {}

int Objet2D::getPerimetre() const {
    return 0;
}

int Objet2D::getAire() const {
    return 0;
}

void Objet2D::afficheInfo() const {
    cout << "Objet2D: dim1=" << dim1 << ", dim2=" << dim2 << endl;
}