#include "stack.hpp"

namespace template_2nd {
// partial specialization of class Stack<> for pointers:
template <typename T>
class Stack<T*> {
 private:
  std::vector<T*> elems;

 public:
  void push(T*);
  T* pop();
  T* top() const;
  bool empty() const { return elems.empty(); }
};

template <typename T>
void Stack<T*>::push(T* elem) {
  elems.push_back(elem);  // append copy of passed elem
}

template <typename T>
T* Stack<T*>::pop() {
  assert(!elems.empty());
  T* p = elems.back();
  elems.pop_back();  // remove last element
  return p;          // and return it (unlike in the general case)
}

template <typename T>
T* Stack<T*>::top() const {
  assert(!elems.empty());
  return elems.back();  // return copy of last element
}

}  // namespace template_2nd
