/*
 * stack_nontype_test.cpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月16日 Author: menmen
 */
#include "stack_nontype.hpp"

#include <iostream>
#include <string>

#include "gtest/gtest.h"

using template_2nd::Stack;

TEST(Stack_NoneType, NoneTypeTest) {
  Stack<int, 20> int20Stack;           // stack of up to 20 ints
  Stack<int, 40> int40Stack;           // stack of up to 40 ints
  Stack<std::string, 40> stringStack;  // stack of up to 40 strings

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

template <char const* name>
class MyClass {
 private:
  char const* mValue;

 public:
  MyClass(char const* value) : mValue(value) {
    EXPECT_EQ(std::string(mValue), std::string("hi"));
  }
};

char const s11[] = "hi";  // internal linkage
TEST(Stack_NoneType, RestrictionsTest) {
  static char const s17[] = "hi";  // internal linkage
  MyClass<s11> m11(s11);
  MyClass<s17> m17(s17);
}
