
#ifndef CLPOINT3D_H
#define CLPOINT3D_H
#include "CLpoint.h"

class CLpoint2D;

class CLpoint3D final : public CLpoint {
public:
    CLpoint3D(double x, double y, double z) : CLpoint({x, y, z}, 3) {}
};

#endif //CLPOINT3D_H
