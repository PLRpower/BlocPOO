#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Objet2D.h"


class Rectangle final : public Objet2D {
public:
    Rectangle();
    Rectangle(int d1, int d2);
    int getLongueur() const;
    int getLargeur() const;

    int getPerimetre() const override;
    int getAire() const override;
    void afficheInfo() const override;
};



#endif //RECTANGLE_H
