//
// Created by max on 24-3-23.
//

#ifndef SANDBOX_NET_H
#define SANDBOX_NET_H

#include <ctime>

#include "convolute.h"
#include "MaxPool.h"
#include "relu.h"
#include "tensor.h"
#include "linear.h"
#include "padding.h"

Tensor net(Tensor img);

#endif //SANDBOX_NET_H
