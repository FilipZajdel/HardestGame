#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum shape_types_t { RECTANGLE };

struct shape_t {
  // public
  /** @brief Checks whether shape contains given point 
   * @return 0 on point contained in shape, any other value otherwise
  */
  uint8_t (*contains)(struct shape_t* shape,
                           unsigned int origin_x,
                           unsigned int origin_y,
                           unsigned int x,
                           unsigned int y);
  uint8_t (*contains_other)(struct shape_t *self, unsigned int origin_x, unsigned int origin_y, unsigned int x, unsigned int y ,struct shape_t *other);
  /** @brief Returns type of shape 
   * @return type
  */
  uint8_t (*get_type)(struct shape_t *shape);
  // private
  uint8_t _type;
};

/** @brief Allocates and initializes new shape 
 * @return pointer to newly allocated shape_t, NULL on allocation failure
*/
struct shape_t* shape_make(enum shape_types_t type);

/** @brief Removes shape */
void shape_remove(struct shape_t **shape);

#ifdef __cplusplus
}
#endif

#endif
