#ifndef MAISON_H
#define MAISON_H


class Room;

class House {
public:
    explicit House(int nbOfRooms);
    void addRoom(Room *room);
    void getNbOfBedrooms() const;
    void getNbOfBathrooms() const;

private:
    Room **maison;
    int nbOfRooms;
    int count;
};



#endif //MAISON_H
