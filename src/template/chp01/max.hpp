/*
 * max.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月16日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP01_MAX_HPP_
#define SRC_TEMPLATE_CHP01_MAX_HPP_
#include <cstring>
#include <type_traits>

namespace template_2nd {

template <typename T>
T max(T a, T b) {
  return b < a ? a : b;
}

template <typename T1, typename T2>
T1 max(T1 a, T2 b) {
  return b < a ? a : b;
}

template <typename T>
T* max(T* a, T* b) {
  return *b < *a ? a : b;
}

char const* max(char const* a, char const* b) {
  return std::strcmp(b, a) < 0 ? a : b;
}

template <typename T>
T max(T const& a, T const& b, T const& c) {
  return max(max(a, b), c);
}

namespace Decltype {
template <typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b < a ? a : b) {
  return b < a ? a : b;
}
}  // namespace Decltype

namespace CommonType {
template <typename T1, typename T2>
std::common_type_t<T1, T2> max(T1 a, T2 b) {
  return b < a ? a : b;
}
}  // namespace CommonType

namespace Default {
template <typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
RT max(T1 a, T2 b) {
  return b < a ? a : b;
}
}  // namespace Default

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP01_MAX_HPP_ */
