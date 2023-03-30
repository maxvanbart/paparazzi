//
// Created by max on 23-3-23.
//

#include "padding.h"

// Function used in order to pad a given input Tensor with zeros allong the edges
Tensor pad(const Tensor& x, int padding) {
    // Initialize a new tensor to store the outputs
    int w_out = x.width + padding * 2;
    int h_out = x.height + padding * 2;
    Tensor y = Tensor(w_out, h_out, x.depth);

    // Iterate over the entire input Tensor and translate that to the desired positions in the new padded Tensor
    for (int i = 0; i < x.width; i++) {
        for (int j = 0; j < x.height; j++) {
            for (int k = 0; k < x.depth; k++) {
                y(i + padding, j+padding, k) = x(i, j, k);
            }
        }
    }
    return y;
}