#include "stack_string.hpp"
#include <iostream>
#include "gtest/gtest.h"
using template_2nd::Stack;

TEST(Stack, PushTest) {

  Stack<int> stack;
  stack.push(1);
  stack.push(2);

  stack.printOn(std::cout);
  EXPECT_EQ(2, stack.top());
}

TEST(Stack, PopTest) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.pop();

  EXPECT_NE(2, stack.top());
}

TEST(Stack, StackStringTest) {
  std::string s1 = "hello";
  Stack<std::string> stack{s1};
  EXPECT_EQ("hello", stack.top());
}
