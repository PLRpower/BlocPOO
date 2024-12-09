#ifndef CLPOINT_H
#define CLPOINT_H

#include <vector>

using namespace std;

class CLpoint {
protected:
    int type;
    vector<double> coordo;

public:
    explicit CLpoint(const vector<double>& coordo, int type);
    virtual ~CLpoint() = default;

    double obtenirDimension() const;

    double distance(const CLpoint& point) const;

    void afficherCoordo() const;

    CLpoint& convertir() const;

    CLpoint& operator=(const CLpoint* point) const;
};



#endif //CLPOINT_H
