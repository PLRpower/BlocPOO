#ifndef BEDROOM_H
#define BEDROOM_H
#include "Room.h"


class Bedroom final : public Room {
public:
    Bedroom(int nbWindows, const string &color, int nbBeds);
    int getNbBeds() const;
    void setNbBeds(int beds);
    bool isBedroom() override;
private:
    int nbBeds;
};



#endif //BEDROOM_H
