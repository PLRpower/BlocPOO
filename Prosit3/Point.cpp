#include "Point.h"
#include <cmath>
#include <iostream>

using namespace std;

Point::Point(const int x, const int y) : x(x), y(y) {}

double Point::distance(const Point& p) const {
    return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

void Point::affiche() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}