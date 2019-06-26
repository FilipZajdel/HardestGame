#include "map.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define _malloc(size) malloc(size)
#define _free(p) free(p)

struct map_field_t** map = NULL;
unsigned int map_x = 0;
unsigned int map_y = 0;

struct map_field_t **get_map(int *x, int *y){
  *x = map_x;
  *y = map_y;

  return map;
}

void entities_map_init(unsigned int x, unsigned int y) {
  if (NULL != map) {
    return;
  }
  map = _malloc(x * sizeof(struct map_field_t*));
  if (map == NULL) {
    return;
  }

  for (int i = 0; i < x; i++) {
    map[i] = _malloc(sizeof(struct map_field_t)*y);
  }

  map_x = x;
  map_y = y;
}

void entities_map_deinit() {
  if (NULL == map) {
    return;
  }

  for (int i = 0; i < map_x; i++) {
    _free(map[i]);
  }

  _free(map);
  map = NULL;
  map_x = 0;
  map_y = 0;
}

// return 0 when ok, other value otherwise
uint8_t coordinates_ok(unsigned int x, unsigned int y) {
  return (x < map_x && y < map_y) ? 0 : 1;
}

const struct map_field_t* entities_map_get_field(unsigned int x, unsigned int y) {
  if (0 == coordinates_ok(x, y)) {
    return (const struct map_field_t*)&map[x][y];
  }
  return NULL;
}

void overwrite_entity(struct map_field_t* field, struct entity_t* entity) {
    field->type = entity->_type;
}

void entities_map_field_modify(unsigned int x,
                          unsigned int y,
                          struct entity_t* new_entity) {
  if (0 == coordinates_ok(x, y)) {
    overwrite_entity(&map[x][y], new_entity);
  }
}

void entities_map_refresh(){
  for(int i=0; i< map_x; i++)
    for(int j=0; j<map_y; j++){
      map[i][j].type = 0;
    }
}