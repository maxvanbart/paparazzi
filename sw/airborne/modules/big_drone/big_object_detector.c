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


bool interface_draw1 = false;
bool interface_draw2 = false;


static struct image_t *big_object_detector(struct image_t *img, uint8_t filter)
{
    bool draw;

    // Set a filter to use both cameras
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

    // Do things
    test_function(filter * 40);

    uint8_t *img_arr = img->buf;
    int h = img->h;
    int w = img->w;
    
    detect_yolo(&img_arr, w, h);
    
    
    // Pass information using a mutex
//    pthread_mutex_lock(&mutex);
//    global_filters[filter-1].color_count = count;
//    global_filters[filter-1].x_c = x_c;
//    global_filters[filter-1].y_c = y_c;
//    global_filters[filter-1].updated = true;
//    pthread_mutex_unlock(&mutex);

    return img;
}



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


void big_detector(void) {
    // Periodic function, here we transfer the results from the image processing to the navigation module
    // Idk how it works or how to do it but it is done here
    int i = 5;
    printf("Hello I am module McModule!\n");
//    test_function(i);
}
