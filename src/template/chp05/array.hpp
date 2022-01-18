/*
 * array.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月17日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP05_ARRAY_HPP_
#define SRC_TEMPLATE_CHP05_ARRAY_HPP_

#include <iostream>

namespace template_2nd {

template <typename T>
struct MyClass;  // primary template

template <typename T, std::size_t SZ>
struct MyClass<T[SZ]>  // partial specialization for arrays of known bounds
{
  static void print() {
      std::cout << "print() for T[" << SZ <<"]\n";
  }
};

template <typename T, std::size_t SZ>
struct MyClass<T (&)[SZ]>  // partial spec. for references to arrays of known
                           // bounds
{
  static void print() {
      std::cout << "print() for T(&)[" << SZ << "]\n";
  }
};

template <typename T>
struct MyClass<T[]>  // partial specialization for arrays of unknown bounds
{
  static void print() {
      std::cout << "print() for T[]\n";
  }
};

template <typename T>
struct MyClass<T (&)[]>  // partial spec. for references to arrays of unknown
                         // bounds
{
  static void print() {
      std::cout << "print() for T(&)[]\n";
  }
};

template <typename T>
struct MyClass<T*>  // partial specialization for pointers
{
  static void print() {
      std::cout << "print() for T*\n";
  }
};

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP05_ARRAY_HPP_ */
