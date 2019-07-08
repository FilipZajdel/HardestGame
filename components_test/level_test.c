#include "../components/level.h"
#include <gtest/gtest.h>
#include <iostream>

typedef struct level_config_t lvl_config;

TEST(level, level_make_and_remove) {
  lvl_config level_config;
  level_config.traps_number = 5;
  level_config.player_start_x = 27;
  level_config.player_start_y = 27;
  level_config.safe_point_x = 17;
  level_config.safe_point_y = 17;
  level_config.dim_x = 30;
  level_config.dim_y = 30;

  uint16_t traps_start_x[5] = {0, 5, 8, 10, 7};
  uint16_t traps_start_y[5] = {0, 0, 8, 5, 7};
  uint16_t traps_end_x[5] = {6, 10, 18, 15, 7};
  uint16_t traps_end_y[5] = {0, 0, 8, 5, 20};

  level_config.traps_start_x = traps_start_x;
  level_config.traps_start_y = traps_start_y;
  level_config.traps_end_x = traps_end_x;
  level_config.traps_end_y = traps_end_y;

  struct level_t* level = level_make(&level_config);

  level_remove(&level);
}

TEST(level, get_collision) {
  lvl_config level_config;
  level_config.traps_number = 5;
  level_config.player_start_x = 27;
  level_config.player_start_y = 27;
  level_config.safe_point_x = 17;
  level_config.safe_point_y = 17;
  level_config.dim_x = 30;
  level_config.dim_y = 30;

  uint16_t traps_start_x[5] = {0, 5, 8, 10, 7};
  uint16_t traps_start_y[5] = {0, 0, 8, 5, 7};
  uint16_t traps_end_x[5] = {6, 10, 18, 15, 7};
  uint16_t traps_end_y[5] = {0, 0, 8, 5, 20};

  level_config.traps_start_x = traps_start_x;
  level_config.traps_start_y = traps_start_y;
  level_config.traps_end_x = traps_end_x;
  level_config.traps_end_y = traps_end_y;

  struct level_t* level = level_make(&level_config);
  EXPECT_EQ(NULL, level->_get_collision(level));
  level_remove(&level);
}

TEST(level, update) {
  lvl_config level_config;
  level_config.traps_number = 5;
  level_config.player_start_x = 27;
  level_config.player_start_y = 27;
  level_config.safe_point_x = 17;
  level_config.safe_point_y = 17;
  level_config.dim_x = 30;
  level_config.dim_y = 30;

  uint16_t traps_start_x[5] = {0, 5, 8, 10, 7};
  uint16_t traps_start_y[5] = {0, 0, 8, 5, 7};
  uint16_t traps_end_x[5] = {6, 10, 18, 15, 7};
  uint16_t traps_end_y[5] = {0, 0, 8, 5, 20};

  level_config.traps_start_x = traps_start_x;
  level_config.traps_start_y = traps_start_y;
  level_config.traps_end_x = traps_end_x;
  level_config.traps_end_y = traps_end_y;

  struct level_t* level = level_make(&level_config);
  level->update(level, UP);
  level_remove(&level);
}

TEST(level, map) {
  lvl_config level_config;
  level_config.traps_number = 5;
  level_config.player_start_x = 27;
  level_config.player_start_y = 27;
  level_config.safe_point_x = 17;
  level_config.safe_point_y = 17;
  level_config.dim_x = 30;
  level_config.dim_y = 30;

  uint16_t traps_start_x[5] = {0, 5, 8, 10, 7};
  uint16_t traps_start_y[5] = {0, 0, 8, 5, 7};
  uint16_t traps_end_x[5] = {6, 10, 18, 15, 7};
  uint16_t traps_end_y[5] = {0, 0, 8, 5, 20};

  level_config.traps_start_x = traps_start_x;
  level_config.traps_start_y = traps_start_y;
  level_config.traps_end_x = traps_end_x;
  level_config.traps_end_y = traps_end_y;

  struct level_t* level = level_make(&level_config);
  level->update(level, NONE);
  bool map_ok = true;

  for (uint8_t i = 0; i < level_config.traps_number; i++) {
    const struct map_field_t* field =
        entities_map_get_field(traps_start_x[i]+1, traps_start_y[i]);

    if (NULL != field)
      if (field->type != TRAP) {
        map_ok = false;
        break;
      }
  }

  EXPECT_TRUE(map_ok);
  level_remove(&level);
}

