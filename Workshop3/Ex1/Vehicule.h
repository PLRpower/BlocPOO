#ifndef VEHICULE_H
#define VEHICULE_H


class Vehicule {
public:
    Vehicule();
    int getMaxSpeed() const;
    int getMileage() const;
    void setMaxSpeed(int speed);
    void setMileage(int km);

private:
    int maxSpeed;
    int mileage;
};



#endif //VEHICULE_H
