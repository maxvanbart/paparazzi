#ifndef PAPARAZZI_INTERFACE_H
#define PAPARAZZI_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

int test_function(int n);
int detect_yolo(const unsigned int *img, const int w, const int h);

#ifdef __cplusplus
}
#endif

#endif