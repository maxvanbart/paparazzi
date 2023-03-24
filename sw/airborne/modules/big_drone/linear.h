//
// Created by max on 23-3-23.
//

#ifndef SANDBOX_LINEAR_H
#define SANDBOX_LINEAR_H

#include <iostream>
#include <random>
#include "tensor.h"

class Linear {
public:
    double* bias;
    int in_features;
    int out_features;
    Tensor weight;

    Linear();
    Linear(int c_in, int c_out);
    ~Linear();

    void init_params();

    Tensor forward(Tensor &x);
};

#endif //SANDBOX_LINEAR_H
