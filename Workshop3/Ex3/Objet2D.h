#ifndef OBJET2D_H
#define OBJET2D_H



class Objet2D {
protected:
    int dim1;
    int dim2;
public:
    virtual ~Objet2D() = default;

    Objet2D();
    Objet2D(int d1, int d2);
    virtual int getPerimetre() const;
    virtual int getAire() const;
    virtual void afficheInfo() const;
};



#endif //OBJET2D_H
