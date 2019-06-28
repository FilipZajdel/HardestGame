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

TEST(map, get_field) {
  entities_map_init(30, 30);

  const struct map_field_t* field = entities_map_get_field(0, 0);
  EXPECT_FALSE(NULL == field);
  entities_map_deinit();
}

TEST(map, get_field_coordinates_by_id) {
  struct entity_t* entities[20];
  for (int i = 0; i < 20; i++) {
    entities[i] = entity_make(TRAP, 0, 0, RECTANGLE);
  }

  entities_map_init(30, 30);

  for(int i=0, entity_ctr=0; i<10; i++){
    for(int k=0; k<2; k++){
      entities_map_field_modify(i,k,entities[entity_ctr]);
      std::cout << i << "\t" << k << "\n";
      entity_ctr++;
    }
  }

  bool got_every_id = true;

  for (struct entity_t** entity = entities; entity < &entities[19]; entity++) {
    unsigned int x, y;
    got_every_id =
        (0 == get_field_coordinates_by_id((*entity)->get_id(*entity), &x, &y));
        std::cout << "id " << (*entity)->get_id(*entity) << "\n";
    if (!got_every_id) {
      break;
    }
  }

  for (int k = 0; k < 20; k++) {
    entity_remove(&entities[k]);
  }

  EXPECT_TRUE(got_every_id);
}