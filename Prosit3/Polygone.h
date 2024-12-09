#ifndef POLYGONE_H
#define POLYGONE_H

#include <vector>
#include "Forme2D.h"

using namespace std;

class Point;

class Polygone : public Forme2D {
protected:
    vector<Point> sommets;

public:
    explicit Polygone(const vector<Point>& points);
    ~Polygone() override = default;

    void afficheSommets() const;
};

#endif //POLYGONE_H
