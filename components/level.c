#include "level.h"
#include <stdlib.h>
#include "map.h"

enum level_states_t level_get_state(struct level_t* l) {
  return l->_state;
}

void update_traps(struct level_t* l) {
  for (struct entity_t** trap = l->_traps;
       trap <= &l->_traps[l->_traps_number - 1]; trap++) {
    (*trap)->move(*trap, 1, 0);
  }
}

void update_player(struct entity_t* player, enum player_move_t move) {
  int delta_x = 0;
  int delta_y = 0;

  switch (move) {
    case LEFT:
      delta_x -= 1;
      break;
    case RIGHT:
      delta_x += 1;
      break;
    case UP:
      delta_y -= 1;
      break;
    case DOWN:
      delta_y += 1;
      break;
    case NONE:
    default:
      break;
  }

  player->move(player, delta_x, delta_y);
}

void update_map(struct level_t* l) {
  
  entities_map_refresh();
  for (struct entity_t** trap = l->_traps; trap < &l->_traps[l->_traps_number];
       trap++) {
    unsigned int x = (*trap)->get_x(*trap);
    unsigned int y = (*trap)->get_y(*trap);
    entities_map_field_modify(x, y, *trap);
  }

  entities_map_field_modify(l->_player->get_x(l->_player),
                            l->_player->get_y(l->_player), l->_player);
  entities_map_field_modify(l->_safe_point->get_x(l->_safe_point),
                            l->_safe_point->get_y(l->_safe_point),
                            l->_safe_point);
}

struct entity_t* get_collision(struct level_t* l) {
  struct entity_t* collided_entity = NULL;

  for (struct entity_t** trap = &l->_traps[0];
       trap <= &l->_traps[l->_traps_number - 1]; trap++) {
    if ((*trap)->collided_with_entity(*trap, l->_player)) {
      collided_entity = *trap;
      break;
    }
  }

  return collided_entity;
}

void level_update(struct level_t* l, enum player_move_t move) {
  update_traps(l);
  update_player(l->_player, move);
  l->_update_map(l);
  struct entity_t* collided_entity = l->_get_collision(l);

  if (NULL == collided_entity) {
    l->_state = LEVEL_RUNNING;
  } else if (collided_entity->get_type(collided_entity) == SAFE_POINT) {
    l->_state = LEVEL_DONE;
  } else if (collided_entity->get_type(collided_entity) == TRAP) {
    l->_state = LEVEL_FAILED;
  } else {
    l->_state = LEVEL_FAILED;
  }
}

struct level_t* level_make(struct level_config_t* lvl_config) {
  struct level_t* level = malloc(sizeof(struct level_t));

  entities_map_init(lvl_config->dim_x, lvl_config->dim_y);
  level->_safe_point = entity_make(SAFE_POINT, lvl_config->safe_point_x,
                                   lvl_config->safe_point_y, RECTANGLE);
  level->_player = entity_make(PLAYER, lvl_config->player_start_x,
                               lvl_config->player_start_y, RECTANGLE);

  level->_traps = malloc(sizeof(struct entity_t*) * lvl_config->traps_number);

  for (uint8_t i = 0; i < lvl_config->traps_number; i++) {
    level->_traps[i] = entity_make(TRAP, lvl_config->traps_start_x[i],
                                   lvl_config->traps_start_y[i], RECTANGLE);
  }

  level->_state = LEVEL_RUNNING;
  level->get_state = level_get_state;
  level->update = level_update;
  level->_traps_number = lvl_config->traps_number;
  level->_get_collision = get_collision;
  level->_update_map = update_map;

  return level;
}

void level_remove(struct level_t** level) {
  if (NULL == *level) {
    return;
  }

  entity_remove(&(*level)->_player);
  entity_remove(&(*level)->_safe_point);

  for (uint8_t i = 0; i < (*level)->_traps_number; i++) {
    entity_remove((*level)->_traps + i);
  }

  free((*level)->_traps);
  free(*level);

  entities_map_deinit();
}
