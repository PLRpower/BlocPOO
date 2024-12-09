#ifndef SCHOOLBUS_H
#define SCHOOLBUS_H

#include <string>
#include "Bus.h"

using namespace std;

class SchoolBus : public Bus {
private:
    string school_name;
public:
    SchoolBus(string sn) {
        school_name = sn;
    }

    string getSchoolName() {
        return school_name;
    }

    void setSchoolName(string sn) {
        school_name = sn;
    }
};
static int countbigbus(SchoolBus t[]){
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (t[i].getSeatingCapacity() > 40 && t[i].getMileage() < 200000) {
            count++;
        }
    }
    return count;
}



#endif //SCHOOLBUS_H
