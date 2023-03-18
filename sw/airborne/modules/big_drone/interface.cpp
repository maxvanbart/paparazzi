#include<iostream>

#include "interface.h"

int test_function(int n) {
    std::cout << "This interface should be on the image processing thread! " << n << std::endl;
    return n * n;
}


int detect_yolo(const uint8_t *img, const int w, const int h) {


    std::cout << "Procseeing image of " << w << " x " << h << ".\n";

    return 5;
}