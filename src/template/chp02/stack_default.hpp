/*
 * stack_default.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月16日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP02_STACK_DEFAULT_HPP_
#define SRC_TEMPLATE_CHP02_STACK_DEFAULT_HPP_
#include <cassert>
#include <vector>
namespace template_2nd {

template <typename T, typename Cont = std::vector<T>>
class Stack {
 private:
  Cont elems;  // elements
 public:
  void push(T const& elem);  // push element
  void pop();                // pop element
  T const& top() const;      // return top element
  bool empty() const {       // return whether the stack isempty
    return elems.empty();
  }
};

template <typename T, typename Cont>
void Stack<T, Cont>::push(T const& elem) {
  elems.push_back(elem);  // append copy of passed elem
}

template <typename T, typename Cont>
void Stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();  // remove last element
}

template <typename T, typename Cont>
T const& Stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();  // return copy of last element
}

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP02_STACK_DEFAULT_HPP_ */
