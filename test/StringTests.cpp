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


TEST(ConstructorTests, FromChar) {
  String s('a');
  EXPECT_TRUE(strcmp(s.data, "a\0") == 0);
  EXPECT_EQ(s.get_size(), 1);
  EXPECT_EQ(s.get_capacity(), 1);
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


TEST(PlusEqualOperator, Char) {
  String str;

  str += 'a';
  EXPECT_EQ(str, String("a"));

  EXPECT_EQ(str += 'b', String("ab"));

  (str += 'c') += 'd';
  EXPECT_EQ(str, String("abcd"));
}

TEST(PlusEqualOperator, CStr) {
  String str;

  str += "aa";
  EXPECT_EQ(str, String("aa"));

  EXPECT_EQ(str += "ab", String("aaab"));

  (str += "ac") += "ad";
  EXPECT_EQ(str, String("aaabacad"));
}

TEST(PlusEqualOperator, String) {
  String str;

  str += String("aa");
  EXPECT_EQ(str, String("aa"));

  EXPECT_EQ(str += String("ab"), String("aaab"));

  (str += String("ac")) += String("ad");
  EXPECT_EQ(str, String("aaabacad"));
}


TEST(PlusOperator, Char) {
  EXPECT_EQ(String("aa") + 'b', String("aab"));
  EXPECT_EQ('a' + String("bb"), String("abb"));
}

TEST(PlusOperator, String) {
  EXPECT_EQ(String("aa") + String("bb"), String("aabb"));
  EXPECT_EQ(String("") + String("bb"), String("bb"));
  EXPECT_EQ(String("aa") + String(""), String("aa"));
  EXPECT_EQ(String("") + String(""), String(""));
}

TEST(PlusOperator, CStr) {
  EXPECT_EQ(String("aa") + "bb", String("aabb"));
  EXPECT_EQ("aa" + String("bb"), String("aabb"));

  EXPECT_EQ(String("aa") + "", String("aa"));
  EXPECT_EQ("" + String("aa"), String("aa"));
}


TEST(EqualOperator, String) {
  String s = "a";

  EXPECT_EQ(s = String("aba"), String("aba"));
  EXPECT_EQ(s, String("aba"));
}

TEST(EqualOperator, CStr) {
  String s = "a";

  // s = "aba";
  EXPECT_EQ(s = "aba", String("aba"));
  EXPECT_EQ(s, String("aba"));
}

}