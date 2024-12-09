#ifndef VEHICULE_H
#define VEHICULE_H

class Vehicule {
public:
    virtual void laver() const = 0;
    virtual ~Vehicule() = default;
};


#endif //VEHICULE_H
