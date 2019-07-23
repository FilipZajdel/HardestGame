#include "config.h"

//////////////////////////////
//
// Level 1
//
//////////////////////////////
extern const char level_name_1[20] = "Hell begins"; 

uint16_t traps_start_y_1[TRAPS_NUMBER_1] = {200, 130, 70, 250, 250, 40};
uint16_t traps_start_x_1[TRAPS_NUMBER_1] = {26, 250, 26, 100, 150, 0};
uint16_t traps_end_x_1[TRAPS_NUMBER_1] = {250, 26, 250, 0, 250, 150};
uint16_t traps_end_y_1[TRAPS_NUMBER_1] = {200, 130, 70, 250, 250, 40};

uint16_t player_start_x_1 = 20;
uint16_t player_start_y_1 = 270;
uint16_t safe_point_x_1 = 150;
uint16_t safe_point_y_1 = 0;
uint16_t traps_number_1 = TRAPS_NUMBER_1;

uint16_t obstacles_number_1 = OBSTACLES_NUMBER_1;
uint16_t obstacles_x_1[OBSTACLES_NUMBER_1] = {125, 0, 0, 0, 170, 170, 170};
uint16_t obstacles_y_1[OBSTACLES_NUMBER_1] = {250, 200, 130, 70, 0, 20, 40};

//////////////////////////////
//
// Level 2
//
//////////////////////////////
extern const char level_name_2[20] = "Total chaos";

uint16_t traps_start_y_2[TRAPS_NUMBER_2] = {10, 5,   125, 100, 100, 80 , 190};
uint16_t traps_start_x_2[TRAPS_NUMBER_2] = {75, 40,  40,  65 , 150, 85 , 85};
uint16_t traps_end_x_2[TRAPS_NUMBER_2] =   {270, 40, 40,  65,  150, 120, 120};
uint16_t traps_end_y_2[TRAPS_NUMBER_2] =   {10, 120, 270, 180, 180, 80 , 190};

uint16_t player_start_x_2 = 125;
uint16_t player_start_y_2 = 125;
uint16_t safe_point_x_2 = 5;
uint16_t safe_point_y_2 = 5;
uint16_t traps_number_2 = TRAPS_NUMBER_2;

uint16_t obstacles_number_2 = OBSTACLES_NUMBER_2;
uint16_t obstacles_x_2[OBSTACLES_NUMBER_2];
uint16_t obstacles_y_2[OBSTACLES_NUMBER_2];

//////////////////////////////
//
// Level 3
//
//////////////////////////////
extern const char level_name_3[20] = "Symmetrick hell"; 

uint16_t traps_start_x_3[TRAPS_NUMBER_3] = {260, 200,  140, 80, 80, 0, 60};
uint16_t traps_start_y_3[TRAPS_NUMBER_3] = {40,  80,  80,  20,  180, 120, 160};

uint16_t traps_end_x_3[TRAPS_NUMBER_3] =   {260, 200, 140, 80, 80, 60, 0};
uint16_t traps_end_y_3[TRAPS_NUMBER_3] =   {240, 200, 200, 100, 260, 120, 160};

uint16_t player_start_x_3 = 280;
uint16_t player_start_y_3 = 140;
uint16_t safe_point_x_3 = 0;
uint16_t safe_point_y_3 = 140;
uint16_t traps_number_3 = TRAPS_NUMBER_3;

uint16_t obstacles_number_3 = OBSTACLES_NUMBER_3;
uint16_t obstacles_x_3[OBSTACLES_NUMBER_3] = 
    {280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, // 1st column from right 
    260, 260, 260, 260, // 2nd column from right
    240, 240, 240, 240, 240, 240, 240, 240, // 3rd column from right
    200, 200, 200, 200, 200, 200, 200, 200, // 4th column from right
    160, 160, 160, 160, // 5th column from right
    140, 140, 140, 140, 140, 140, 140, 140, // 6th column from right
    80, 80, 80, 80, 80}; // 7th column from right
uint16_t obstacles_y_3[OBSTACLES_NUMBER_3] = 
    {0, 20, 40, 60, 80, 100, 180, 200, 220, 240, 260, 280, // 1st column from right
    0, 20, 260, 280,
    0, 20, 40, 60, 220, 240, 260, 280,
    0, 20, 40, 60, 220, 240, 260, 280,
    0, 20, 260, 280,
    0, 20, 40, 60, 220, 240, 260, 280,
    0, 280, 120, 140, 160
    };