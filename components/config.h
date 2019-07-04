#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

#define RECTANGLE_HEIGHT 30
#define RECTANGLE_WIDTH 30

#define TRAPS_NUMBER_1 6
extern uint8_t traps_start_x_1[TRAPS_NUMBER_1];
extern uint8_t traps_start_y_1[TRAPS_NUMBER_1];
extern uint8_t traps_end_x_1[TRAPS_NUMBER_1];
extern uint8_t traps_end_y_1[TRAPS_NUMBER_1];

extern uint8_t player_start_x_1;
extern uint8_t player_start_y_1;
extern uint8_t safe_point_x_1;
extern uint8_t safe_point_y_1;

#define LEVEL_NUMBER 1

#define CONFIG_LEVEL_1 {    \
/*dim_x*/ 25, /*dim_y*/ 25, /*traps_number*/ TRAPS_NUMBER_1, \
/*traps_start_x*/traps_start_x_1, /*traps_start_y*/traps_start_y_1, \
/*traps_enx_x*/traps_end_x_1, /*traps_end_y*/traps_end_y_1, \
/*player_start_point_x*/player_start_x_1, /*player_start_point_y*/player_start_y_1, \
/*safe_point_x*/ safe_point_x_1,/*safe_point_y*/safe_point_y_1}

#ifdef __cpluplus
}
#endif

#endif
