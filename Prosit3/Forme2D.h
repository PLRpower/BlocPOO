#ifndef OBJET2D_H
#define OBJET2D_H


class Forme2D {
public:
    virtual ~Forme2D() = default;

    virtual float getPerimetre() const = 0;
    virtual float getAire() const = 0;
    virtual void afficheInfo() const = 0;
};

#endif //OBJET2D_H
