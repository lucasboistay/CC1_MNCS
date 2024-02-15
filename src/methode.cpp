//
// Created by lucas on 15/02/2024.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <Eigen/Dense>

#include "../include/methode.h"

#include <functional>

float deriv2_3tc(std::function <float(const float)> f, const float t_0, const float h){
    return (f(t_0 + h) - 2*f(t_0) + f(t_0 - h))/(h*h);
}