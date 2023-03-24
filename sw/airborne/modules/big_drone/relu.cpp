//
// Created by max on 23-3-23.
//

#include "relu.h"

Tensor relu(const Tensor &x) {
    Tensor y(x.width, x.height, x.depth);
    for (int i = 0; i < x.size; i++) {
        y.data[i] = std::max(x.data[i], 0.0);
    }
    return y;
}