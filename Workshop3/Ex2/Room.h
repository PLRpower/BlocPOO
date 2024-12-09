#ifndef PIECE_H
#define PIECE_H

#include <string>

using namespace std;

class Room {
public:
    virtual ~Room() = default;

    Room(int nbWindows, const string &color);
    int getNbWindows() const;
    void setNbWindows(int windows);
    string getColor() const;
    void setColor(const string &color);
    virtual bool isBedroom();
    virtual bool isBathroom();
private:
    int nbWindows;
    string color;
};

#endif //PIECE_H
