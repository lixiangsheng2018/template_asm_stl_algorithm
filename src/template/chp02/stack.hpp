/*
 * stack.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月16日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP02_STACK_HPP_
#define SRC_TEMPLATE_CHP02_STACK_HPP_

#include <cassert>
#include <vector>
#include <ostream>

namespace template_2nd {

template <typename T>
class Stack {
 private:
  std::vector<T> elems;

 public:
  //  Stack (Stack const&);
  //  Stack& operator= (Stack const&);
  //  bool operator== (Stack const& lhs, Stack const& rhs);

  void printOn(std::ostream& strm) const {
    for (T const& elem : elems) {
      strm << elem << ' ';
    }
  }

  friend std::ostream& operator<<(std::ostream& strm, Stack<T> const& s) {
    s.printOn(strm);
    return strm;
  }

  void push(T const& elem);
  void pop();
  T const& top() const;
  bool empty() const { return elems.empty(); }
};

template <typename T>
void Stack<T>::push(T const& elem) {
  elems.push_back(elem);  // append copy of passed elem
}

template <typename T>
void Stack<T>::pop() {
  assert(!elems.empty());
  elems.pop_back();  // remove last element
}

template <typename T>
T const& Stack<T>::top() const {
  assert(!elems.empty());
  return elems.back();  // return copy of last element
}

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP02_STACK_HPP_ */
