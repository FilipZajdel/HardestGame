#include "entity.h"
#include <stdlib.h>

uint8_t entity_get_type(struct entity_t* entity) {
  return entity->_type;
}

unsigned int get_x(struct entity_t *e){
  return e->_coord_x;
}

unsigned int get_y(struct entity_t *e){
  return e->_coord_y;
}

void move(struct entity_t* entity, int delta_x, int delta_y) {
  entity->_coord_x += delta_x;
  entity->_coord_y += delta_y;
}

uint8_t collided(struct entity_t* entity, unsigned int x, unsigned int y) {
  return entity->_shape->contains(entity->_shape, entity->_coord_x,
                                  entity->_coord_y, x, y);
}

uint8_t collided_with_entity(struct entity_t* self, struct entity_t* other) {
  return self->_shape->contains(self->_shape, self->_coord_x,
                                  self->_coord_y, other->_coord_x,
                                  other->_coord_y);
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

  entity->collided_with_entity = collided_with_entity;
  entity->_type = entity_type;
  entity->_coord_x = x;
  entity->_coord_y = y;
  entity->collided = &collided;
  entity->get_type = &entity_get_type;
  entity->move = &move;
  entity->get_x = get_x;
  entity->get_y = get_y;
  return entity;
}

void entity_remove(struct entity_t** entity) {
  if (entity != NULL) {
    shape_remove(&((*entity)->_shape));
    free(*entity);
    *entity = NULL;
  }
}