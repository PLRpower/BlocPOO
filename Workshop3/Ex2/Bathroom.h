#ifndef BATHROOM_H
#define BATHROOM_H
#include "Room.h"


class Bathroom final : public Room {
public:
    Bathroom(int nbWindows, const string &color, bool shower);
    bool getHasShower() const;
    void setHasShower(bool shower);
    bool isBathroom() override;
private:
    bool hasShower;
};



#endif //BATHROOM_H
