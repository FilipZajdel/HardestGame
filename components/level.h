#ifndef LEVEL_H
#define LEVEL_H

#include "map.h"
#include "entity.h"

#ifdef __cplusplus
extern "C" {
#endif
/** For now levels are hardcoded in files containted in directory levels */

enum level_states_t {RUNNING, GAME_OVER};

struct level_t {
    struct entity_t *_entities;
    enum level_states_t _state;

};



#ifdef __cplusplus
}
#endif

#endif