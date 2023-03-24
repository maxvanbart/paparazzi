//
// Created by max on 23-3-23.
//

#include "linear.h"

Tensor Linear::forward(Tensor &x) {
    Tensor x_flat = x.flatten();
    Tensor y(out_features, 1, 1);
    if (x_flat.size != in_features) {
        std::cout << "WARNING: input does not match expected input features" << std::endl;
    }

    for (int i = 0; i < out_features; i++) {
        y(i, 0, 0) = bias[i];
        for (int j = 0; j < x_flat.width; j++) {
            y(i, 0, 0) += x_flat(j, 0, 0) * weight(i, j, 0);
        }
    }
    return y;
}

Linear::Linear() {
    bias = nullptr;
    in_features = 0;
    out_features = 0;
    weight = Tensor();
}

Linear::~Linear() {
    delete[] bias;
}

Linear::Linear(int c_in, int c_out) {
    in_features = c_in;
    out_features = c_out;
    bias = new double[c_out];
    weight = Tensor(out_features, in_features, 1);
}

void Linear::init_params() {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, 0.667);
    std::cout << "[ ";
    for (int i = 0; i < out_features; i++) {
        bias[i] = distribution(generator);
        std::cout << bias[i] << " ";
    }
    std::cout << "]" << std::endl << std::endl;
    for (int j = 0; j < weight.size; j++) {
        weight.data[j] = distribution(generator);
    }
    weight.print();
}
