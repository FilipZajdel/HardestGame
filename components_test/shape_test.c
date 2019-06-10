#include "../components/shape.h"
#include <gtest/gtest.h>
#include <stdint.h>

TEST(making_shape, shape) {

  shape_t* shape = shape_make(RECTANGLE);
  EXPECT_EQ((uint8_t)RECTANGLE, shape->get_type(shape));
  shape_remove(&shape);
}

TEST(deleting_shape, shape) {
  shape_t* shape = shape_make(RECTANGLE);
  shape_remove(&shape);
  EXPECT_EQ(NULL, shape);
}
