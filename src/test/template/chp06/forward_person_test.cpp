/*
 * forward_person_test.cpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月19日 Author: menmen
 */
#include "forward_person.hpp"

#include "gtest/gtest.h"

TEST(ForwardPerson, ForwardPersonTest) {
  using template_2nd::Person;

  std::string s = "张三";
  Person p1(s);
  std::string expect_str = "TMPL-CONSTR for 张三";
  EXPECT_EQ(expect_str, p1.value_);

  Person p2("李四");
  expect_str = "TMPL-CONSTR for 李四";
  EXPECT_EQ(expect_str, p2.value_);

  Person p3(p1);
  expect_str = "COPY - NONCONSTR Person 张三";
  EXPECT_EQ(expect_str, p3.value_);
}
