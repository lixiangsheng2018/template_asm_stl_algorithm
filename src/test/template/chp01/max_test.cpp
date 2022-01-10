#include "max.hpp"
#include "gtest/gtest.h"

#include <iostream>
#include <string>

TEST(Max, IntMax) {
  EXPECT_EQ(1, template_2nd::max(0, 1));
}

TEST(Max, StringMax) {
  std::string expected = "abc";

  std::string str1 = "ABC";
  std::string str2 = "abc";
  EXPECT_EQ(expected, template_2nd::max(str1, str2));
  EXPECT_EQ(expected, template_2nd::max<std::string>(str1, str2));
}




