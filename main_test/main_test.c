#include <gtest/gtest.h>
#include "../components_test/shape_test.c"
#include "../components_test/entity_test.c"
#include "../components_test/map_test.c"
#include "../components_test/level_test.c"
#include "../components_test/game_test.c"


main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
}