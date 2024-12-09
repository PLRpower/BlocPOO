#ifndef CLPOINT2D_H
#define CLPOINT2D_H
#include "CLpoint.h"

class CLpoint3D;

class CLpoint2D final : public CLpoint {
public:
    CLpoint2D(double x, double y) : CLpoint({x, y}, 2) {}
};

#endif //CLPOINT2D_H
