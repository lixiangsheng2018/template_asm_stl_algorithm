/*
 * stack_final.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月18日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP05_STACK_FINAL_HPP_
#define SRC_TEMPLATE_CHP05_STACK_FINAL_HPP_
#include <cassert>
#include <deque>
#include <memory>
template <typename T, template <typename Elem, typename = std::allocator<Elem>>
                      class Cont = std::deque>
class Stack {
 private:
  Cont<T> elems;

 public:
  void push(T const&);
  void pop();
  T const& top() const;
  bool empty() const { return elems.empty(); }

  // assign stack of elements of type T2
  template <typename T2,
            template <typename Elem2, typename = std::allocator<Elem2>>
            class Cont2>
  Stack<T, Cont>& operator=(Stack<T2, Cont2> const&);

  // to get access to private members of any Stack with elements of type T2:
  template <typename, template <typename, typename> class>
  friend class Stack;
};

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::push(T const& elem) {
  elems.push_back(elem);
}

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T, template <typename, typename> class Cont>
T const& Stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();
}

template <typename T, template <typename, typename> class Cont>
template <typename T2, template <typename, typename> class Cont2>
Stack<T, Cont>& Stack<T, Cont>::operator=(Stack<T2, Cont2> const& op2) {
  elems.clear();
  elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
  return *this;
}

#endif /* SRC_TEMPLATE_CHP05_STACK_FINAL_HPP_ */
