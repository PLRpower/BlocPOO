//
// Created by pault on 24/11/2024.
//

#ifndef CLPARCOURS3D_H
#define CLPARCOURS3D_H
#include "CLparcours.h"

class CLparcours3D final : public CLparcours {
public:
    explicit CLparcours3D(const int nbPoints) : CLparcours(nbPoints, 3) {}
};

#endif //CLPARCOURS3D_H
