#include "../components/map.h"
#include <gtest/gtest.h>

TEST(map, write_and_get_field) {
  entities_map_init(1, 1);

  struct entity_t* entity = entity_make(PLAYER, 20, 30, RECTANGLE);

  entities_map_field_modify(0, 0, entity);

  EXPECT_FALSE(entity->get_type(entity) == SAFE_POINT);
  EXPECT_TRUE(entity->get_type(entity) == PLAYER);
  EXPECT_FALSE(entity->get_type(entity) == TRAP);

  entity_remove(&entity);

  entities_map_deinit();
}
