#include <gtest/gtest.h>
#include "../components_test/shape_test.c"
#include "../components_test/entity_test.c"


main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}