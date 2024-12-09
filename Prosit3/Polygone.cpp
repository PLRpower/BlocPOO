#include "Polygone.h"
#include "Point.h"

Polygone::Polygone(const vector<Point>& points) : sommets(points) {}

void Polygone::afficheSommets() const {
    for (const Point& p : sommets) {
        p.affiche();
    }
}