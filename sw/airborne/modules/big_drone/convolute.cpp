//
// Created by max on 23-3-23.
//

#include "convolute.h"
// This class is mainly based on the Conv2D functionality included in the python pytorch library

// Default constructor for the convolutional layer class
Conv2d::Conv2d() {
    in_channels = 0;
    out_channels = 0;
    kernel_size = 0;
    stride = 0;
    padding = 0;
    weight = nullptr;
    bias = nullptr;
}

// Constructor used to setup a convolutional layer
Conv2d::Conv2d(int in_channels_, int out_channels_, int kernel_size_, int stride_, int padding_) {
    in_channels = in_channels_;
    out_channels = out_channels_;
    kernel_size = kernel_size_;
    stride = stride_;
    padding = padding_;

//    std::cout << "Printing kernel weights" << std::endl;
    // Store the different kernels for the convolutional layer as an array of Tensor class objects
    weight = new Tensor[out_channels];
    for (int i = 0; i < out_channels; i++) {
        weight[i] = Tensor(kernel_size, kernel_size, in_channels);
    }
    // Add a array to store the biases of the convolutional filters.
    bias = new double[out_channels];
}

// destructor of the class in order to prevent memory leaks due to the initialized arrays
Conv2d::~Conv2d() {
    delete[] weight;
    delete[] bias;
}

// Function to populate the weights with random numbers for testing purposes
void Conv2d::init_params() {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, 0.667);

    // Iterate over all weights and initialize random weights
    for (int i = 0; i < out_channels; i++) {
        bias[i] = distribution(generator);
        for (int j = 0; j < weight[i].size; j++) {
            weight[i].data[j] = distribution(generator);
        }
//        std::cout << "weight " << i << std::endl;
//        weight[i].print();
    }
}

// Function to print the biases
void Conv2d::print() {
    std::cout << "Biases: [ ";
    for (int i = 0; i < out_channels; i++) {
        std::cout << bias[i] << " ";
    }
    std::cout << "]\n";
}

// Function for the forward propagation through the layer
Tensor Conv2d::forward(const Tensor &x) {
    // Add padding to the input
    Tensor x_padded = pad(x, padding);

    // Calculate the desired output size
    int Hp = 1 + (x.height + 2 * padding - kernel_size) / stride;
    int Wp = 1 + (x.width + 2 * padding - kernel_size) / stride;

    // Initialize an output tensor
    Tensor y(Wp, Hp, out_channels);

    // Iterate over all positions and kernels to calculate the output layers
    for (int K = 0; K < out_channels; K++) {
        for (int I = 0; I < Wp; I++) {
            for (int J = 0; J < Hp; J++) {
                // Calculate an individual output by iterating over the kernel and adding the results together
                double result = 0;
                for (int i = 0; i < kernel_size; i++) {
                    for (int j = 0; j < kernel_size; j++) {
                        for (int k = 0; k < x.depth; k++)
                            result += x(I * stride + i, J * stride + j, k) * weight[K](i, j, k) + bias[K];
                    }
                }
                // Store the result in the correct position of the output
                y(I, J, K) = result;
            }
        }
    }
    return y;
}
