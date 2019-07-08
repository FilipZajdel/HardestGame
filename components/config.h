#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

#define RECTANGLE_HEIGHT 20
#define RECTANGLE_WIDTH 20

#define TRAPS_NUMBER_1 3
#define OBSTACLES_NUMBER_1 1
#define TRAPS_VELOCITY_1 2
extern uint16_t traps_number_1;
extern uint16_t traps_start_x_1[TRAPS_NUMBER_1];
extern uint16_t traps_start_y_1[TRAPS_NUMBER_1];
extern uint16_t traps_end_x_1[TRAPS_NUMBER_1];
extern uint16_t traps_end_y_1[TRAPS_NUMBER_1];

extern uint16_t player_start_x_1;
extern uint16_t player_start_y_1;
extern uint16_t safe_point_x_1;
extern uint16_t safe_point_y_1;

extern uint16_t obstacles_number_1;
extern uint16_t obstacles_x_1[OBSTACLES_NUMBER_1];
extern uint16_t obstacles_y_1[OBSTACLES_NUMBER_1];

#define LEVEL_NUMBER 1

#define CONFIG_LEVEL_1 {    \
/*dim_x*/ 300, /*dim_y*/ 300, /*traps_number*/ traps_number_1, \
/*traps_start_x*/traps_start_x_1, /*traps_start_y*/traps_start_y_1, \
/*traps_enx_x*/traps_end_x_1, /*traps_end_y*/traps_end_y_1, \
/*player_start_point_x*/player_start_x_1, /*player_start_point_y*/player_start_y_1, \
/*safe_point_x*/ safe_point_x_1,/*safe_point_y*/safe_point_y_1, \
/*obstacles_x*/obstacles_x_1 ,/*obstacles_y*/obstacles_y_1, \
obstacles_number_1}

#ifdef __cplusplus
}
#endif

#endif
