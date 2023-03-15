#include<iostream>

#include "test_interface.h"

int testfunction(int n) {
    std::cout << "This works!" << std::endl;
    return n * n;
}