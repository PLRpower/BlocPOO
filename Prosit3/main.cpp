#include "Carre.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main() {
    const Point p1(0, 0);
    const Point p2(0, 5);
    const Point p3(5, 5);

    const Triangle triangle(p1, p2, p3);

    const Carre carre(p1, 5);

    const Rectangle rectangle(p1, p3);

    const Cercle cercle(p1, 5);

    triangle.afficheInfo();
    carre.afficheInfo();
    rectangle.afficheInfo();
    cercle.afficheInfo();

    return 0;
}
