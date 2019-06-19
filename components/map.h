#ifndef MAP_H
#define MAP_H

#include "entity.h"

#ifdef __cplusplus
extern "C" {
#endif

struct map_field_t {
  enum entity_types_t type;
};

/** @brief Initializes map with given size
 * @param width size of entities in row
 * @param height size of entities in column
 */
void entities_map_init(unsigned int width, unsigned int height);

/** @brief Deinitializes map of the entities */
void entities_map_deinit();

/** @brief Returns entity of given coordinates */
const struct map_field_t* entities_map_get_field(unsigned int x,
                                                 unsigned int y);

/** @breif Overwrites field of given coordinates with provided new entity */
void entities_map_field_modify(unsigned int x,
                               unsigned int y,
                               struct entity_t* new_entity);

#ifdef __cplusplus
}
#endif

#endif