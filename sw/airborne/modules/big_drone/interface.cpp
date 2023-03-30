#include<iostream>

#include "interface.h"
#include "net.h"
#include "tensor.h"

// Testing function which should not run in the current implementation
int test_function(int n) {
    std::cout << "This interface should be on the image processing thread! " << n << std::endl;

    Tensor t8(240, 520, 3);
    std::cout << t8.width << " " << t8.height << " " << t8.depth << std::endl;
    Tensor t9 = net(t8);
    std::cout << t9.width << " " << t9.height << " " << t9.depth << std::endl;

    return n * n;
}

// Other testing function to test the passthrough of the image to C++
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