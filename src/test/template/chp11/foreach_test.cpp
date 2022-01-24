/*
 * foreach_test.cpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月24日 Author: menmen
 */
#include "foreach.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"

class MyClass {
 public:
  void memfunc(int i) const {
    std::cout << "MyClass::memfunc() called for: " << i << '\n';
  }
};

TEST(Foreach, ForeachTest) {
  using template_2nd::foreach;
  std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

  foreach(
      primes.begin(), primes.end(),
      [](std::string const& prefix, int i) {
        std::cout << prefix << i << '\n';
      },
      "- value:");

  MyClass obj;
  foreach(primes.begin(), primes.end(), &MyClass::memfunc, obj);
}

TEST(ForeachForward, ForeachForwardTest) {
  using template_2nd::forward::call;

  MyClass obj;
  call(&MyClass::memfunc, obj, 3);
}
