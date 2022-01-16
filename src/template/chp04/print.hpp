/*
 * print.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月16日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP04_PRINT_HPP_
#define SRC_TEMPLATE_CHP04_PRINT_HPP_
#include <iostream>
#include <array>

namespace template_2nd {

void print() {}

template <typename T, typename... Types>
void print(T firstArg, Types... args) {
  std::cout << firstArg << '\n';  // print first argument
  print(args...);                 // call print() for remaining arguments
}

template <typename... T>
auto foldSum(T... s) {
  return (... + s);  // ((s1 + s2) + s3) ...
}

template <typename T>
class AddSpace {
 private:
  T const& ref;  // refer to argument passed in constructor
 public:
  AddSpace(T const& r) : ref(r) {}
  friend std::ostream& operator<<(std::ostream& os, AddSpace<T> s) {
    return os << s.ref << ' ';  // output passed argument and a space
  }
};

template <typename... Args>
void print_final(Args... args) {
  (std::cout << ... << AddSpace(args)) << '\n';
}

template <typename... T>
void printDoubled(T const&... args) {
  print_final(args + args...);
}

template <typename C, typename... Idx>
void printElems(C const& coll, Idx... idx) {
  print_final(coll[idx]...);
}

template <std::size_t... Idx, typename C>
void printIdx(C const& coll) {
  print_final(coll[Idx]...);
}

template <std::size_t...>
struct Indices {};

template <typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>) {
  print_final(std::get<Idx>(t)...);
}

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP04_PRINT_HPP_ */
