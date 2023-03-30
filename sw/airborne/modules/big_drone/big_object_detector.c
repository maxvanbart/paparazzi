#include "big_object_detector.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "pthread.h"

// Required modules
#include "modules/core/abi.h"

// Submodules
#include "interface.h"

// Declare external variables
bool interface_draw1 = false;
bool interface_draw2 = false;


// Interfacing function which interfaces the C part of the module with the network written in C++
static struct image_t *big_object_detector(struct image_t *img, uint8_t filter)
{
    bool draw;

    // Get the draw variable for the used camera
    switch (filter){
        case 1:
            draw = interface_draw1;
            break;
        case 2:
            draw = interface_draw2;
            break;
        default:
            return img;
    };

    // Get the necessary properties from the image for the further calculations
    uint8_t *img_arr = img->buf;
    int h = img->h;
    int w = img->w;

    // Calculate the total length of the image array knowing the height, width and the amount of datapoints per pixel
    // This is two due to the uyvy format
    int size = h * w * 2;

    // Convert the image array to standard C types in order to pass it to C++
    unsigned int int_arr[size];
    for (int i = 0; i < size; i++) {
        int_arr[i] = img_arr[i];
    }

    // Pass the image and the resolution to the detection algorithm
    detect_yolo(int_arr, w, h);

    return img;
}


// Code to send the right filter with the camera based on the original orange avoider code
struct image_t *big_object_detector1(struct image_t *img, uint8_t camera_id);
struct image_t *big_object_detector1(struct image_t *img, uint8_t camera_id __attribute__((unused)))
{
    return big_object_detector(img, 1);
}

struct image_t *big_object_detector2(struct image_t *img, uint8_t camera_id);
struct image_t *big_object_detector2(struct image_t *img, uint8_t camera_id __attribute__((unused)))
{
    return big_object_detector(img, 2);
}


// Initialization function for the module
void big_detector_init(void) {
    #ifdef COLOR_OBJECT_DETECTOR_CAMERA1
        #ifdef COLOR_OBJECT_DETECTOR_DRAW1
            interface_draw1 = COLOR_OBJECT_DETECTOR_DRAW1;
        #endif

        cv_add_to_device(&COLOR_OBJECT_DETECTOR_CAMERA1, big_object_detector1, COLOR_OBJECT_DETECTOR_FPS1, 0);
    #endif

    #ifdef COLOR_OBJECT_DETECTOR_CAMERA2
        #ifdef COLOR_OBJECT_DETECTOR_DRAW2
            interface_draw2 = COLOR_OBJECT_DETECTOR_DRAW2;
        #endif

        cv_add_to_device(&COLOR_OBJECT_DETECTOR_CAMERA2, big_object_detector2, COLOR_OBJECT_DETECTOR_FPS2, 1);
    #endif
}

// Periodic function for the module
void big_detector(void) {
    // Periodic function, here we transfer the results from the image processing to the navigation module
    // Idk how it works or how to do it but it is done here
    //    int i = 5;
    //    printf("Hello I am module McModule!\n");
    //    test_function(i);
}
