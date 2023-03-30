//
// Created by jen on 23/03/2023.
//

#include "MaxPool.h"


// Function to simulate a maxpooling layer, no class was made as this function does not store any weights and biases
Tensor maxpool(const Tensor& x, int KS, int stride) {
    // Calculate the output dimensions and initialize a new Tensor to store the output
    int w_out_max = floor(1 + (x.width - KS)/stride);
    int h_out_max = floor(1 + (x.height - KS)/stride);
    Tensor y = Tensor(w_out_max, h_out_max, x.depth);

    // Loop over all desired kernels which need to be calculated in the layer
    for (int k = 0; k < x.depth; k++) {
        for (int I = 0; I < w_out_max; I++) {
            for (int J = 0; J < h_out_max; J++) {
                // Loop over all elements in the kernel and compare them to the current maximum value
                double max_val = -1e6;
                for (int i = 0; i < KS; i++) {
                    for (int j = 0; j < KS; j++) {
                        max_val = std::max(max_val,x(I*stride+i, J*stride+j, k));
                    }
                }
//                std::cout << "Found maximum value of " << max_val << " for I=" << I << " and J=" << J << std::endl;
                // Store the maximum value in its desired spot in the output matrix
                y(I,J,k) = max_val;
            }
        }
    }



    return y;
}