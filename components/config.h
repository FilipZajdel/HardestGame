#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

#define RECTANGLE_HEIGHT 20
#define RECTANGLE_WIDTH 20

#define PLAYER_VELOCITY 2 // points per iteration
#define LEVEL_NUMBER 2  // Tells how many levels are available

/********************************************************
 * ***     ****** **      ** ******   ***          **   
 * **      **     **      ** **       **          *** 
 * **      ******  **    **  *****    **           **
 * **      **       **  **   **       **           **
 * ******* *******    **     *******  ********   ******
 * *****************************************************/

#define TRAPS_NUMBER_1 6
#define OBSTACLES_NUMBER_1 7

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

#define CONFIG_LEVEL_1 {    \
/*dim_x*/ 300, /*dim_y*/ 300, /*traps_number*/ traps_number_1, \
/*traps_start_x*/traps_start_x_1, /*traps_start_y*/traps_start_y_1, \
/*traps_enx_x*/traps_end_x_1, /*traps_end_y*/traps_end_y_1, \
/*player_start_point_x*/player_start_x_1, /*player_start_point_y*/player_start_y_1, \
/*safe_point_x*/ safe_point_x_1,/*safe_point_y*/safe_point_y_1, \
/*obstacles_x*/obstacles_x_1 ,/*obstacles_y*/obstacles_y_1, \
obstacles_number_1}

#define TRAPS_VELOCITY_1 1


/********************************************************
 * ***     ****** **      ** ******   ***        ***   
 * **      **     **      ** **       **        *   * 
 * **      ******  **    **  *****    **           *
 * **      **       **  **   **       **         **
 * ******* *******    **     *******  ******** *******
 * *****************************************************/

#define TRAPS_NUMBER_2 7
#define OBSTACLES_NUMBER_2 0

extern uint16_t traps_number_2;
extern uint16_t traps_start_x_2[TRAPS_NUMBER_2];
extern uint16_t traps_start_y_2[TRAPS_NUMBER_2];
extern uint16_t traps_end_x_2[TRAPS_NUMBER_2];
extern uint16_t traps_end_y_2[TRAPS_NUMBER_2];

extern uint16_t player_start_x_2;
extern uint16_t player_start_y_2;
extern uint16_t safe_point_x_2;
extern uint16_t safe_point_y_2;

extern uint16_t obstacles_number_2;
extern uint16_t obstacles_x_2[OBSTACLES_NUMBER_2];
extern uint16_t obstacles_y_2[OBSTACLES_NUMBER_2];

#define CONFIG_LEVEL_2 {    \
/*dim_x*/ 300, /*dim_y*/ 300, /*traps_number*/ traps_number_2, \
/*traps_start_x*/traps_start_x_2, /*traps_start_y*/traps_start_y_2, \
/*traps_enx_x*/traps_end_x_2, /*traps_end_y*/traps_end_y_2, \
/*player_start_point_x*/player_start_x_2, /*player_start_point_y*/player_start_y_2, \
/*safe_point_x*/ safe_point_x_2,/*safe_point_y*/safe_point_y_2, \
/*obstacles_x*/obstacles_x_2 ,/*obstacles_y*/obstacles_y_2, \
obstacles_number_2}

#define TRAPS_VELOCITY_2 1

#include <stdio.h>

#ifndef n_debug
//#define debug_log(msg,...) printf(msg,  ##__VA_ARGS__)
#define debug_log(msg,...) fprintf(stderr, msg, ##__VA_ARGS__)
#else
#define debug_log(msg,...)
#endif

#ifdef __cplusplus
}
#endif

#endif
