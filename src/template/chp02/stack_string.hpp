#include <cassert>
#include <deque>
#include <iostream>
#include <string>

#include "stack.hpp"

namespace template_2nd {

template <>
class Stack<std::string> {
 private:
  std::deque<std::string> elems;  // elements
 public:
  Stack(std::string elem) : elems({std::move(elem)}) {}

  void push(std::string const&);   // push element
  void pop();                      // pop element
  std::string const& top() const;  // return top element
  bool empty() const {             // return whether the stack is empty
    return elems.empty();
  }
};

void Stack<std::string>::push(std::string const& elem) {
  elems.push_back(elem);  // append copy of passed elem
}

void Stack<std::string>::pop() {
  assert(!elems.empty());
  elems.pop_back();  // remove last element
}

std::string const& Stack<std::string>::top() const {
  assert(!elems.empty());
  return elems.back();  // return copy of last element
}

}  // namespace template_2nd
