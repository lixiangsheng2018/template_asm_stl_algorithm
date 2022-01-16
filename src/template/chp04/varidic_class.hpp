/*
 * varidic_class.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月17日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP04_VARIDIC_CLASS_HPP_
#define SRC_TEMPLATE_CHP04_VARIDIC_CLASS_HPP_

#include <string>
#include <unordered_set>

namespace template_2nd {

class Customer {
 private:
  std::string name;

 public:
  Customer(std::string const& n) : name(n) {}
  std::string getName() const { return name; }
};

struct CustomerEq {
  bool operator()(Customer const& c1, Customer const& c2) const {
    return c1.getName() == c2.getName();
  }
};

struct CustomerHash {
  std::size_t operator()(Customer const& c) const {
    return std::hash<std::string>()(c.getName());
  }
};

// define class that combines operator() for variadic base classes:
template <typename... Bases>
struct Overloader : Bases... {
  using Bases::operator()...;  // OK since C++17
};

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP04_VARIDIC_CLASS_HPP_ */
