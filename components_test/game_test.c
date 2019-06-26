#include "../components/game.h"
#include <gtest/gtest.h>

TEST(game, make_and_remove_memcheck) {
  // this test is supposed to be invoked with valgrind
  struct game_t* game = game_make();
  game_remove(&game);
}

TEST(game, init) {
  struct game_t* game = game_make();

  game->init(game);
  EXPECT_EQ(1, game->_level_idx);
  EXPECT_EQ(LEVEL_RUNNING, game->_level->_state);

  game_remove(&game);
}

TEST(game, update){
  struct game_t* game = game_make();

  game->init(game);
  game->update(game, UP);
   // what to do here ??
  EXPECT_TRUE(false);
  
  game_remove(&game);
}