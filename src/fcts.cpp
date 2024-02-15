//
// Created by lucas on 15/02/2024.
//

#include "../include/fcts.h"

#include <cmath>

float k;

float cosh_kt(const float t){
    return (exp(k*t) + exp(-k*t))/2.;
}

float d2cosh_kt(const float t){
    return k*k*(exp(k*t) + exp(-k*t))/2.; //dérivée seconde de cosh(kt)
}