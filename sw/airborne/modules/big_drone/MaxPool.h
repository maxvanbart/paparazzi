//
// Created by jen on 23/03/2023.
//

#ifndef SANDBOX_MAXPOOL_H
#define SANDBOX_MAXPOOL_H

#include"padding.h"

#include<cmath>
#include<iostream>


Tensor maxpool(const Tensor& x, int KS, int stride);



#endif //SANDBOX_MAXPOOL_H
