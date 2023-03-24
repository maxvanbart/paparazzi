#ifndef SANDBOX_TENSOR_H
#define SANDBOX_TENSOR_H

#include <iostream>

class Tensor {
public:
    Tensor();
    Tensor(int d1, int d2, int d3);
    ~Tensor();
    double& operator[] (int i) const;
    double& operator() (int i, int j, int k) const;

    // Copy constructor
    Tensor(const Tensor& other);
    // Move constructor
    Tensor(Tensor&& other) noexcept ;

    // Copy assignment operator
    Tensor operator=(const Tensor& other);
    // Move assignment operator
    Tensor& operator=(Tensor&& other);

    Tensor flatten();

    void print();

    int height;
    int width;
    int depth;
    int size;
    double* data;
};

#endif
