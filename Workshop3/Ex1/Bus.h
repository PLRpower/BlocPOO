#ifndef BUS_H
#define BUS_H
#include "Vehicule.h"


class Bus : public Vehicule {
public:
    Bus();
    int getSeatingCapacity() const;
    void setSeatingCapacity(int capacity);
    void getInfo() const;
private:
    int seatCapacity;
};


#endif //BUS_H
