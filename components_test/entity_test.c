#include "../components/entity.h"
#include <gtest/gtest.h>

TEST(make_unmake_entity, entity) {
  struct entity_t* entity = NULL;
  entity = entity_make(PLAYER, 20, 30, RECTANGLE);

  EXPECT_FALSE(NULL == entity);

  entity_remove(&entity);
}

TEST(entity, move) {
  struct entity_t* entity = NULL;
  entity = entity_make(PLAYER, 20, 30, RECTANGLE);

  entity->move(entity, 20, 40);

  EXPECT_EQ(entity->_coord_x, 40);
  EXPECT_EQ(entity->_coord_y, 70);

  entity_remove(&entity);
}

TEST(entity, get_type) {
  struct entity_t* entity = NULL;
  entity = entity_make(PLAYER, 20, 30, RECTANGLE);

  EXPECT_EQ(entity->_type, PLAYER);

  entity_remove(&entity);
}

TEST(entity, collided) {
  struct entity_t* entity = entity_make(PLAYER, 20, 30, RECTANGLE);

  unsigned int x = 20, y = 30;
  const int delta_x = 10, delta_y = 10;
  bool collided = false;

  for (int move_ctr = 0; move_ctr < 40; move_ctr++) {
    entity->move(entity, delta_x, delta_y);
    x += delta_x;
    y += delta_y;

    if (0 == entity->collided(entity, x, y)) {
      collided = true;
      break;
    }
  }

  EXPECT_TRUE(collided);
  entity_remove(&entity);
}

TEST(entity, not_collided) {
  struct entity_t* entity = entity_make(PLAYER, 20, 30, RECTANGLE);

  EXPECT_FALSE(0 == entity->collided(entity, 50, 80));

  entity_remove(&entity);
}

