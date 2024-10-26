#include <gtest/gtest.h>
#include "../src/String.h"

#include <string.h>


namespace custom_string {


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


TEST(CompareOperatorTests, Equality) {
  EXPECT_TRUE(String("123") == String("123"));
  EXPECT_FALSE(String("123") != String("123"));

  EXPECT_TRUE(String("") == String(""));
  EXPECT_FALSE(String("") != String(""));

  EXPECT_TRUE(String("123") != String(""));
  EXPECT_FALSE(String("123") == String(""));
}

TEST(CompareOperatorTests, Compare) {
  EXPECT_TRUE(String("1") < String("12"));
  EXPECT_TRUE(String("12") < String("2"));

  EXPECT_FALSE(String("1") > String("12"));
  EXPECT_FALSE(String("12") > String("2"));


  EXPECT_TRUE(String("1") <= String("12"));
  EXPECT_TRUE(String("12") <= String("2"));
  
  EXPECT_FALSE(String("1") >= String("12"));
  EXPECT_FALSE(String("12") >= String("2"));

  EXPECT_TRUE(String("") <= String(""));
  EXPECT_TRUE(String("12") <= String("2"));
}


TEST(SquareBracketsTests, Const) {
  const String const_str("qwe123");
  String str("qwe123");

  EXPECT_EQ(const_str[0], 'q');
  EXPECT_EQ(str[0], 'q');

  EXPECT_NE(const_str[1], '_');
  EXPECT_NE(str[1], '_');
}

TEST(SquareBracketsTests, NonConst) {
  String str("qwe123");

  str[0] = 'a';
  EXPECT_EQ(str, String("awe123"));
}

}

