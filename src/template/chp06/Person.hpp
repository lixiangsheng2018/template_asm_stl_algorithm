/*
 * Person.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月20日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP06_PERSON_HPP_
#define SRC_TEMPLATE_CHP06_PERSON_HPP_

#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
template <typename T>

using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;
class Person {
 private:
  std::string name;

 public:
  // generic constructor for passed initial name:
  template <typename STR, typename = EnableIfString<STR>>
  explicit Person(STR&& n) : name(std::forward<STR>(n)) {
  std::cout << "TMPL-CONSTR for " << name << "\n";
  }

  // copy and move constructor:
  Person(Person const& p) : name(p.name) {
    std::cout << "COPY - CONSTR Person " << name << "\n";
  }

  Person(Person&& p) : name(std::move(p.name)) {
    std::cout << "MOVE - CONSTR Person " << name << "\n";
  }
};

#endif /* SRC_TEMPLATE_CHP06_PERSON_HPP_ */
