
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"
#include "Polygone.h"


class Rectangle : public Polygone {
public:
    Rectangle(const Point& p1, const Point& p2);
    ~Rectangle() override = default;

    float getPerimetre() const override;
    float getAire() const override;
    void afficheInfo() const override;

private:
    int longueur;
    int largeur;
};



#endif //RECTANGLE_H
