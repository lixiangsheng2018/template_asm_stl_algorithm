/*
 * forward_person.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月19日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP06_FORWARD_PERSON_HPP_
#define SRC_TEMPLATE_CHP06_FORWARD_PERSON_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <utility>

namespace template_2nd {
class Person {
 private:
  std::string name_;
  std::stringstream ss_;

 public:
  std::string value_;

 public:
  // generic constructor for passed initial name:
  template <typename STR>
  explicit Person(STR&& n) : name_(std::forward<STR>(n)) {
    ss_ << "TMPL-CONSTR for " << name_;
    value_ = ss_.str();
  }

  // copy and move constructor:
  Person(Person const& p) : name_(p.name_) {
    ss_ << "COPY - CONSTR Person " << name_;
    value_ = ss_.str();
  }

  Person(Person& p) : name_(p.name_) {
    ss_ << "COPY - NONCONSTR Person " << name_;
    value_ = ss_.str();
  }

  Person(Person&& p) : name_(std::move(p.name_)) {
    ss_ << "MOVE - CONSTR Person " << name_;
    value_ = ss_.str();
  }
};

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP06_FORWARD_PERSON_HPP_ */
