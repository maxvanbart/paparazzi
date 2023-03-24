#ifndef SANDBOX_CONVOLUTE_H
#define SANDBOX_CONVOLUTE_H

#include <random>
#include <iostream>
#include <cmath>

#include "tensor.h"
#include "padding.h"

class Conv2d {
public:
    Tensor *weight;
    double *bias;

    int in_channels;
    int out_channels;
    int kernel_size;
    int stride;
    int padding;

    Conv2d();
    Conv2d(int in_channels_, int out_channels_, int kernel_size_, int stride_, int padding_);
    ~Conv2d();


    Tensor forward(const Tensor& x);
    void init_params();
    void print();

};

#endif
