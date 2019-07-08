#include "shape.h"
#include "config.h"

#include <stdlib.h>

uint8_t contains(struct shape_t* shape,
                 unsigned int origin_x,
                 unsigned int origin_y,
                 unsigned int x,
                 unsigned int y) {
  unsigned int contains = 1;

  switch (shape->_type) {
    case RECTANGLE:
      if (x >= origin_x && x <= origin_x + RECTANGLE_WIDTH && y >= origin_y &&
          y <= origin_y + RECTANGLE_HEIGHT) {
        contains = 0;
      }
      // printf("x:%d origin_x:%d y: %d origin_y: %d\n", x, origin_x, y,
      // origin_y);
      break;
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

  return shape;
}

void shape_remove(struct shape_t** shape) {
  if (NULL != *shape) {
    free(*shape);
  }
  *shape = NULL;
}