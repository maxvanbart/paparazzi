#ifndef MAX1167_H
#define MAX1167_H

#include "std.h"

#define MAX1167_NB_CHAN 4

extern void max1167_init( void );
extern void max1167_read( void );
//extern volatile uint8_t max1167_data_available;

#define STA_MAX1167_IDLE           0
#define STA_MAX1167_SENDING_REQ    1
#define STA_MAX1167_WAIT_EOC       2
#define STA_MAX1167_READING_RES    3 
#define STA_MAX1167_DATA_AVAILABLE 4
extern volatile uint8_t max1167_status;

extern uint16_t max1167_values[MAX1167_NB_CHAN];

extern void max1167_hw_init( void );
#include "max1167_hw.h"

#endif /* MAX1167_H */
