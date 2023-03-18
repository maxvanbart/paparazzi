#ifndef PAPARAZZI_INTERFACE_H
#define PAPARAZZI_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

int test_function(int n);
int detect_yolo(uint8_t *img, int w, int h);

#ifdef __cplusplus
}
#endif

#endif