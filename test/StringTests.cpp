#include <gtest/gtest.h>
#include "../src/String.h"

using custom_string::String;

TEST(StringTests, EmptyString) {
  String s;
  EXPECT_TRUE(s.isEqual("\n"));
  EXPECT_EQ(s.get_size(), 0);
  EXPECT_EQ(s.get_capacity(), 0);
}