#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
#include "Polygone.h"


class Triangle final : public Polygone {
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    ~Triangle() override = default;

    float getPerimetre() const override;
    float getAire() const override;
    void afficheInfo() const override;

private:
    int longueur1;
    int longueur2;
    int longueur3;
};



#endif //TRIANGLE_H
