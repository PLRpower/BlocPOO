//
// Created by pault on 24/11/2024.
//

#ifndef CLPARCOURS2D_H
#define CLPARCOURS2D_H
#include "CLparcours.h"

class CLparcours2D final : public CLparcours {
public:
    explicit CLparcours2D(const int nbPoints) : CLparcours(nbPoints, 2) {}
};

#endif //CLPARCOURS2D_H
