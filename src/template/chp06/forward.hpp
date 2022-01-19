/*
 * forward.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月19日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP06_FORWARD_HPP_
#define SRC_TEMPLATE_CHP06_FORWARD_HPP_
#include <iostream>
#include <string>
#include <utility>

namespace template_2nd {

class X {};

std::string g(X&) { return "g() for variable"; }

std::string g(X const&) { return "g() for constant"; }

std::string g(X&&) { return "g() for movable object"; }

// let f() perfect forward argument val to g():
template <typename T>
std::string f(T&& val) {
  return g(
      std::forward<T>(val));  // call the right g() for any passed argument val
}

}  // namespace template_2nd
#endif /* SRC_TEMPLATE_CHP06_FORWARD_HPP_ */
