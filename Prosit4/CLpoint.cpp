#include "CLpoint.h"

#include <iostream>
#include <vector>
#include <cmath>

#include "CLpoint2D.h"
#include "CLpoint3D.h"

using namespace std;

CLpoint::CLpoint(const vector<double>& coordo, const int type) : type(type), coordo(coordo) {}

double CLpoint::obtenirDimension() const {
    return coordo.size();
}

double CLpoint::distance(const CLpoint& point) const {
    double sommeDesCarres = 0.0;
    for (int i = 0; i < obtenirDimension(); ++i) {  // Distance euclidienne
        const double diff = point.coordo[i] - coordo[i];
        sommeDesCarres += diff * diff;
    }
    return sqrt(sommeDesCarres);
}

void CLpoint::afficherCoordo() const {
    cout << "Les coordonnees du point : " << this << " et de type " << type << ", sont : (" << coordo[0] << ":" << coordo[1] << ")(" << coordo[2] << ")" << endl;
}

CLpoint& CLpoint::convertir() const {
    if(coordo.size() == 2) {
        return *new CLpoint3D(coordo[0], coordo[1], 0.0);
    }
    return *new CLpoint2D(coordo[0], coordo[1]);
}