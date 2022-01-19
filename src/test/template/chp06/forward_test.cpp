/*
 * forward_test.cpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月19日 Author: menmen
 */
#include "forward.hpp"

#include "gtest/gtest.h"

TEST(Forward, ForwardTest) {
  using template_2nd::X;
  X v;
  X const c;
  std::string expect_var = "g() for variable";
  std::string expect_const = "g() for constant";
  std::string expect_move = "g() for movable object";
  EXPECT_EQ(expect_var, f(v));
  EXPECT_EQ(expect_const, f(c));
  EXPECT_EQ(expect_move, f(X()));
  EXPECT_EQ(expect_move, f(std::move(v)));
}
