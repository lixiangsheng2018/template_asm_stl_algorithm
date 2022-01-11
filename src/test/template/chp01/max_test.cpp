#include "max.hpp"

#include <iostream>
#include <string>

#include "gtest/gtest.h"

TEST(Max, IntMax) { EXPECT_EQ(1, template_2nd::max(0, 1)); }

TEST(Max, StringMax) {
  std::string expected = "abc";

  std::string str1 = "ABC";
  std::string str2 = "abc";
  EXPECT_EQ(expected, template_2nd::max(str1, str2));
  EXPECT_EQ(expected, template_2nd::max<std::string>(str1, str2));
}

TEST(Max, CStringMax) {
  char const* expected = "abc";

  char const* str1 = "ABC";
  char const* str2 = "abc";
  EXPECT_EQ(expected, template_2nd::max(str1, str2));
}

TEST(Max, ThreeCStringMax) {
  char const* expected = "bcd";

  char const* str1 = "ABC";
  char const* str2 = "abc";
  char const* str3 = "bcd";
  EXPECT_EQ(expected, template_2nd::max(str1, str2, str3));
}

TEST(Max, IntFloat) {
  EXPECT_EQ(7, template_2nd::max(4, 7.2));
  EXPECT_EQ(7.2, template_2nd::max(7.2, 4));
}

TEST(Max, IntFloatDecltype) {
  EXPECT_EQ(7.2, template_2nd::Decltype::max(4, 7.2));
}

TEST(Max, IntFloatCommonType) {
  EXPECT_EQ(7.2, template_2nd::CommonType::max(4, 7.2));
}

TEST(Max, IntFloatDefault) {
  auto ret1 = template_2nd::Default::max<int, double>(4, 7.2);
  EXPECT_EQ(7.2, ret1);
  auto ret2 = template_2nd::Default::max<int, double, long double>(4, 7.2);
  EXPECT_EQ(7.2, ret2);
}
