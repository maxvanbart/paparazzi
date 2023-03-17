#include<iostream>

#include "interface.h"

int test_function(int n) {
    std::cout << "This interface should be on the image processing thread! " << n << std::endl;
    return n * n;
}