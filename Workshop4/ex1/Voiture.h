#ifndef VOITURE_H
#define VOITURE_H

class Voiture {
protected:
    static int nombreObjets;
    int vitesseMax;
    int vitesse;
    int acceleration;

public:
    Voiture();
    Voiture(int vmax, int accel);
    virtual ~Voiture();

    static int getNombreObjets();
    void initialiser(int vmax, int accel);
    virtual void accelerer();
};

#endif // VOITURE_H
