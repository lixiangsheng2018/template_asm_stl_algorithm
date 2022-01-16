/*
 * stack_auto_test.cpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月16日 Author: menmen
 */
#include "stack_auto.hpp"

#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

#include "gtest/gtest.h"

using template_2nd::Stack;

template <auto T>  // take value of any possible nontype parameter (since C++17)
class Message {
private:
  std::stringstream ss;
 public:
  std::string print() {
    ss << T;
    return ss.str();
  }
};

TEST(Stack_Auto, AutoTest1) {
  Message<42> msg1;
  EXPECT_EQ(std::string("42"), msg1.print());
  static char const s[] = "hello";
  std::string str = "hello";
  Message<s> msg2;
  EXPECT_EQ(str, msg2.print());
}

TEST(Stack_Auto, AutoTest2) {
  Stack<int, 20u> int20Stack;          // stack of up to 20 ints
  Stack<int, 40> int40Stack;           // stack of up to 40 ints
  Stack<std::string, 40> stringStack;  // stack of up to 40 strings

  auto size1 = int20Stack.size();
  auto size2 = stringStack.size();
  auto result1 = std::is_same<decltype(size1), decltype(size2)>::value;
  EXPECT_EQ(false, result1);
  auto result2 = std::is_same_v<decltype(size1), decltype(size2)>;
  EXPECT_EQ(false, result2);

  int20Stack.push(7);
  EXPECT_EQ(7, int20Stack.top());
  int20Stack.pop();

  std::string expect_str = "hello";
  stringStack.push("hello");
  EXPECT_EQ(expect_str, stringStack.top());
  stringStack.pop();

  EXPECT_EQ(0, int20Stack.size());
  EXPECT_EQ(0, int40Stack.size());
  EXPECT_EQ(0, stringStack.size());
}
