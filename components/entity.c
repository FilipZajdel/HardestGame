#include "entity.h"
#include <stdlib.h>

uint8_t entity_get_type(struct entity_t* entity) {
  return entity->_type;
}

void move(struct entity_t *entity, int delta_x, int delta_y) {
  entity->_coord_x += delta_x;
  entity->_coord_y += delta_y;
}

uint8_t collided(struct entity_t* entity, unsigned int x, unsigned int y) {
  return entity->_shape->contains(entity->_shape, entity->_coord_x, entity->_coord_y, x, y);
}

struct entity_t* entity_make(enum entity_types_t entity_type,
                             unsigned int x,
                             unsigned int y,
                             enum shape_types_t shape_type) {
  struct entity_t* entity = malloc(sizeof(struct entity_t));
  if (NULL == entity) {
    return NULL;
  }

  entity->_shape = shape_make(shape_type);
  if (NULL == entity->_shape) {
    free(entity);
    return NULL;
  }

  entity->_type = entity_type;
  entity->_coord_x = x;
  entity->_coord_y = y;
  entity->collided = &collided;
  entity->get_type = &entity_get_type;
  entity->move = &move;
}

void entity_remove(struct entity_t** entity) {
  if (entity != NULL) {
    shape_remove(&((*entity)->_shape));
    free(*entity);
    *entity = NULL;
  }
}