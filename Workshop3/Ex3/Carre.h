#ifndef CUBE_H
#define CUBE_H
#include "Objet2D.h"


class Carre final : public Objet2D {
public:
    Carre();
    explicit Carre(int cote);

    int getCote() const;

    int getPerimetre() const override;
    int getAire() const override;
    void afficheInfo() const override;
};



#endif //CUBE_H
