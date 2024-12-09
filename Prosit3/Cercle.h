#ifndef CERCLE_H
#define CERCLE_H
#include "Forme2D.h"
#include "Point.h"


class Cercle final : public Forme2D {
public:
    Cercle(const Point& centre, float rayon);

    float getPerimetre() const override;
    float getAire() const override;
    void afficheInfo() const override;

private:
    Point centre;
    float rayon;
};



#endif //CERCLE_H
