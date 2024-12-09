#ifndef CLPARCOURS_H
#define CLPARCOURS_H
#include "CLpoint.h"


class CLparcours {
protected:
    int nbPoints;
    int type;
    vector<CLpoint*> points;

public:
    explicit CLparcours(int nbPoints, int type);

    virtual ~CLparcours() = default;

    void ajouterPoint(CLpoint* p);

    double calculDistance() const;

    void message() const;
};



#endif //CLPARCOURS_H
