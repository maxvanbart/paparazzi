//
// Created by max on 24-3-23.
//

#include "net.h"
#include <chrono>

Tensor net(Tensor img) {

    auto start = std::chrono::high_resolution_clock::now();

    Tensor x = img;
    Conv2d l1(3, 8, 3, 1, 1);
    Conv2d l2(8, 12, 3, 1, 1);
    Conv2d l3(12, 20, 3, 1, 1);
    Conv2d l4(20, 12, 1, 1, 0);
    Conv2d l5(12, 20, 3, 1, 1);
    Conv2d l6(20, 40, 3, 1, 1);
    Conv2d l7(40, 20, 1, 1, 0);
    Conv2d l8(20, 40, 3, 1, 1);
    Conv2d l9(40, 100, 3, 1, 1);
    Conv2d l10(100, 40, 1, 1, 0);
    Conv2d l11(40, 100, 3, 1, 1);
    Conv2d l12(100, 40, 1, 1, 0);
    Conv2d l13(40, 100, 3, 1, 1);
    Conv2d l14(100, 150, 3, 1, 1);
    Conv2d l15(150, 40, 1, 1, 0);
    Conv2d l16(40, 150, 3, 1, 1);
    Conv2d l17(150, 40, 1, 1, 0);
    Conv2d l18(40, 150, 3, 1, 1);

    l1.init_params();
    l2.init_params();
    l3.init_params();
    l4.init_params();
    l5.init_params();
    l6.init_params();
    l7.init_params();
    l9.init_params();
    l8.init_params();
    l10.init_params();
    l11.init_params();
    l12.init_params();
    l13.init_params();
    l14.init_params();
    l15.init_params();
    l16.init_params();
    l17.init_params();
    l18.init_params();

    // downsize 448 * 448 input
    x = maxpool(x, 2, 2);
    x = l1.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l2.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l3.forward(x);
    x = relu(x);
    x = l4.forward(x);
    x = relu(x);
    x = l5.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l6.forward(x);
    x = relu(x);
    x = l7.forward(x);
    x = relu(x);
    x = l8.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l9.forward(x);
    x = relu(x);
    x = l10.forward(x);
    x = relu(x);
//    x = l11.forward(x);
//    x = relu(x);
//    x = l12.forward(x);
//    x = relu(x);
    x = l13.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l14.forward(x);
    x = relu(x);
//    x = l15.forward(x);
//    x = relu(x);
//    x = l16.forward(x);
//    x = relu(x);
//    x = l17.forward(x);
//    x = relu(x);
//    x = l18.forward(x);
//    x = relu(x);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Time taken for forward pass: "<< duration.count() << " ms" << std::endl;

    return x;
}