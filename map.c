#include "map.h"
#include "config.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define _malloc(size) malloc(size)
#define _free(p) free(p)

struct map_field_t** map = NULL;
unsigned int map_x = 0;
unsigned int map_y = 0;

struct map_field_t** get_map(int* x, int* y) {
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
    map[i] = _malloc(sizeof(struct map_field_t) * y);
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

const struct map_field_t* entities_map_get_field(unsigned int x,
                                                 unsigned int y) {
  if (0 == coordinates_ok(x, y)) {
    return (const struct map_field_t*)&map[x][y];
  }
  return NULL;
}

void overwrite_field(struct map_field_t* field, struct entity_t* entity) {
  debug_log("Overwriting %u\n", entity->get_id(entity));
  field->type = entity->get_type(entity);
  field->id = entity->get_id(entity);
}

void entities_map_field_modify(unsigned int x,
                               unsigned int y,
                               struct entity_t* new_entity) {
  if (0 == coordinates_ok(x, y)) {
    overwrite_field(&map[x][y], new_entity);
  }
}

void entities_map_refresh() {
  for (int i = 0; i < map_x; i++){
    for (int j = 0; j < map_y; j++) {
      map[i][j].type = 0;
      map[i][j].id = 0;
    }
  }
}

uint8_t get_field_coordinates_by_id(uint16_t id, unsigned int* x, unsigned int* y) {

  for(int col=0; col<map_x; col++){
    for(int row=0; row<map_y; row++){
      if(id == map[col][row].id){
        *x = col;
        *y = row;
        return 0;
      }
    }
  }
  return 1;
}
