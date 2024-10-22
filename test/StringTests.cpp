#include <gtest/gtest.h>
#include "../src/String.h"

#include <string.h>


namespace custom_string {


// ConstructorTests begin
TEST(ConstructorTests, EmptyString) {
  String s;
  EXPECT_TRUE(strcmp(s.data, "") == 0);
  EXPECT_EQ(s.get_size(), 0);
  EXPECT_EQ(s.get_capacity(), 0);
}


TEST(ConstructorTests, FromCStr) {
  char c_str[]="Hello, world";
  String s(c_str);
  EXPECT_TRUE(strcmp(s.data, c_str) == 0);
  EXPECT_EQ(s.get_size(), strlen(c_str));
}


TEST(ConstructorTests, FromString) {
  char c_str[]="Hello, world";
  String s1(c_str);
  s1.data[0] = '\0';
  String s2(s1);
  EXPECT_EQ(s1.get_size(), s2.get_size());
  EXPECT_TRUE(memcmp(s1.data, s2.data, s1.get_size()) == 0);
}
// ConstructorTests end

}

