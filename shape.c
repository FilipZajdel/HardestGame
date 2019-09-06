#include "shape.h"
#include "config.h"

#include <stdlib.h>

uint8_t contains(struct shape_t* shape,
                 unsigned int origin_x,
                 unsigned int origin_y,
                 unsigned int x,
                 unsigned int y) {
  uint8_t contains = 1;

  switch (shape->_type) {
    case RECTANGLE:
      if ((x >= origin_x) && (x < (origin_x+RECTANGLE_WIDTH)) && (y>=origin_y) &&
          (y<(origin_y+RECTANGLE_HEIGHT))) {
        contains = 0;
      }
      break;
    default:
      break;
  }
  return contains;
}

uint8_t contains_rectangle_helper(struct shape_t *self,unsigned int origin_x, unsigned int origin_y, unsigned int x, unsigned int y){

    uint8_t contains = 1;

    for(unsigned int other_x = x; ((other_x < x+RECTANGLE_WIDTH) && (0 != contains)); other_x++){

      for(unsigned int other_y = y; other_y < y+RECTANGLE_WIDTH; other_y++){
        if(0 == self->contains(self, origin_x, origin_y, other_x, other_y)){
          debug_log("other_x: %u\tother_y: %u\n", other_x, other_y);
          contains = 0;
          break;
        }
      }
    }

    return contains;
}

uint8_t contains_other(struct shape_t *self, unsigned int origin_x, unsigned int origin_y, unsigned int x, unsigned int y ,struct shape_t *other){

    uint8_t contains = 1;

    switch(self->_type) {
      case RECTANGLE:
        switch(other->_type){
          case RECTANGLE:
            contains = contains_rectangle_helper(self, origin_x, origin_y, x, y);
            break;
          default:
            break;
        }
      default:
        break;
    }
    return contains;
}

uint8_t get_type(struct shape_t* shape) {
  return (uint8_t)shape->_type;
}

struct shape_t* shape_make(enum shape_types_t type) {
  struct shape_t* shape = malloc(sizeof(struct shape_t));
  if (NULL == shape) {
    return NULL;
  }

  shape->_type = type;
  shape->get_type = &get_type;
  shape->contains = &contains;
  shape->contains_other = &contains_other;

  return shape;
}

void shape_remove(struct shape_t** shape) {
  if (NULL != *shape) {
    free(*shape);
  }
  *shape = NULL;
}
