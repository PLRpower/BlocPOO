#ifndef CARRE_H
#define CARRE_H
#include "Rectangle.h"


class Carre final : public Rectangle {
public:
    explicit Carre(const Point& p1, float cote);
    ~Carre() override = default;

    void afficheInfo() const override;
};



#endif //CARRE_H
