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

TEST(containing_other_shape, shape){
  shape_t* shape = shape_make(RECTANGLE);
  shape_t* other_shape = shape_make(RECTANGLE);

  EXPECT_EQ(0, shape->contains_other(shape, 0, 0, 5, 5, other_shape));

  shape_remove(&shape);
  shape_remove(&other_shape);
}

TEST(containing_point_in_shape, shape){
  shape_t* shape = shape_make(RECTANGLE);
  EXPECT_EQ(0, shape->contains(shape, 0, 0, 5, 5));
  shape_remove(&shape);
}