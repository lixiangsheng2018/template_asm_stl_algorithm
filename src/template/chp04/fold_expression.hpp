/*
 * fold_expression.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月16日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP04_FOLD_EXPRESSION_HPP_
#define SRC_TEMPLATE_CHP04_FOLD_EXPRESSION_HPP_

namespace template_2nd {

struct Node {
  int value;
  Node* left;
  Node* right;
  Node(int i = 0) : value(i), left(nullptr), right(nullptr) {}
};

auto left = &Node::left;
auto right = &Node::right;

// traverse tree, using fold expression:
template <typename T, typename... TP>
Node* traverse(T np, TP... paths) {
  return (np->*...->*paths);  // np ->* paths1 ->* paths
}

template <typename T1, typename... TN>
constexpr bool isHomogeneous(T1, TN...) {
  return (std::is_same<T1, TN>::value && ...);  // since C++17
}

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP04_FOLD_EXPRESSION_HPP_ */
