#include<iostream>

#include "interface.h"

int test_function(int n) {
    std::cout << "This interface works! " << n << std::endl;
    return n * n;
}