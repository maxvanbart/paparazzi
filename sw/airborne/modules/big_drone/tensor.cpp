#include "tensor.h"


// Default constructor
Tensor::Tensor() {
    width = 0;
    height = 0;
    depth = 0;
    size = 0;
    data = nullptr;
}

// Constructor with specified dims
Tensor::Tensor(int d1, int d2, int d3) {
    width = d1;
    height = d2;
    depth = d3;
    size = width * height * depth;
    data = new double[size];
}

// Copy constructor
Tensor::Tensor(const Tensor &other) {
    width = other.width;
    height = other.height;
    depth = other.depth;
    size = other.size;
    data = new double[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// Move constructor
Tensor::Tensor(Tensor &&other) noexcept: width(other.width), height(other.height), depth(other.depth), size(other.size), data(other.data)
{
    other.width = 0;
    other.height = 0;
    other.depth = 0;
    other.size = 0;
    other.data = nullptr;
}

// Default destructor to avoid memory leaks
Tensor::~Tensor() {
    delete[] data;
    size = 0;
}

// Function to get the i'th element stored in the tensor (neglecting the 3 dimensional property)
double &Tensor::operator[](int i) const {
    if (i < size) {
        return data[i];
    }
    // Workaround to always get a result, might break things later
    return data[0];
}

// Function to get the specific value at some 3-dimensional location in the Tensor
double &Tensor::operator()(int i, int j, int k) const {
    int entry = i + width * j + width * height * k;
    if (entry < size) {
        return data[entry];
    } else {
        return data[0];
    }
}

// Copy assignment operator
Tensor Tensor::operator=(const Tensor &other) {
    width = other.width;
    height = other.height;
    depth = other.depth;
    size = other.size;
    data = new double[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}
// Move assignment operator
Tensor &Tensor::operator=(Tensor &&other) {
    if (this != &other) {
        delete[] data;
        data = other.data; other.data = nullptr;
        width = other.width; other.width = 0;
        height = other.height; other.height = 0;
        depth = other.depth; other.depth = 0;
        size = other.size; other.size = 0;
    }
    return *this;
}

// Function to print the contents of the Tensor in a format which can be interpreted by a human as a 3d-matrix
void Tensor::print() {

    for (int k = 0; k < depth; k++) {
        for (int j = 0; j < height; j++) {
            std::cout << "[ ";
            for (int i = 0; i < width; i ++) {
                std::cout << data[i + width * j + width * height * k] << " ";
            }
            std::cout << "]\n";
        }
        std::cout << "\n";
    }
}

// Turn the Tensor into a flat Tensor to transfer from the convolution to the linear layer
Tensor Tensor::flatten() {
    Tensor y(size, 1, 1);
    for (int i = 0; i < size; i++) {
        y.data[i] = data[i];
    }
    return y;
}
