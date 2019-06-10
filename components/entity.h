#ifndef ENTITY_H
#define ENTITY_H

#include "shape.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum entity_types_t { PLAYER, TRAP, SAFE_POINT };

struct entity_t {
  // public
  /** @brief Returns type of entity */
  uint8_t (*get_type)(struct entity_t*);
  /** @brief Moves entity by given deltas */
  void (*move)(struct entity_t*,int delta_x, int delta_y);
  /** @brief Checks whether entity collides with given point 
   * @return 0 on collision, other value otherwise
  */
  uint8_t (*collided)(struct entity_t*, unsigned int, unsigned int);
  // private
  uint8_t _type;
  unsigned int _coord_x, _coord_y;
  struct shape_t* _shape;
};

/** @brief Initializes entity_t with given arguments
 * @return pointer to allocated entity_t, NULL when allocation fails */
struct entity_t* entity_make(enum entity_types_t entity_type,
                             unsigned int x,
                             unsigned int y,
                             enum shape_types_t shape_type);

/** @brief Removes entity */
void entity_remove(struct entity_t **);

#ifdef __cplusplus
}
#endif

#endif