//
// Created by max on 23-3-23.
//

#include "relu.h"

// Relu function to add non-linearity to the network
Tensor relu(const Tensor &x) {
    // Make an output Tensor and iterate over the input using the desired non-linearity
    Tensor y(x.width, x.height, x.depth);
    for (int i = 0; i < x.size; i++) {
//        y.data[i] = std::max(x.data[i], 0.0);
        // Modification to the ReLU in order to make it a Leaky ReLU
        y.data[i] = std::max(x.data[i], 0.0) + 0.01 * std::min(x.data[i], 0.0);
    }
    return y;
}