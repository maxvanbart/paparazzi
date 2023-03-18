#include<iostream>

#include "interface.h"

int test_function(int n) {
    std::cout << "This interface should be on the image processing thread! " << n << std::endl;
    return n * n;
}


int detect_yolo(const unsigned int *img, const int w, const int h) {


    std::cout << "Processing image of " << w << " x " << h << ".\n";

//    // This code dumps the entire image into the program output for reasons
//    // don't know why I though this would be a good idea as it currently just clutters the log
//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < w; j++) {
//            std::cout << img[w * i + j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;

    return 5;
}