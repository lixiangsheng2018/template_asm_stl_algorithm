/*
 * foreach.hpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月24日 Author: menmen
 */

#ifndef SRC_TEMPLATE_CHP11_FOREACH_HPP_
#define SRC_TEMPLATE_CHP11_FOREACH_HPP_
#include <functional>
#include <utility>

namespace template_2nd {

template <typename Iter, typename Callable, typename... Args>
void foreach (Iter current, Iter end, Callable op, Args const&... args) {
  while (current != end) {
    std::invoke(op, args..., *current);
    ++current;
  }
}

namespace forward {

template <typename Callable, typename... Args>
decltype(auto) call(Callable&& op, Args&&... args) {
  return std::invoke(std::forward<Callable>(op), std::forward<Args>(args)...);
}

}  // namespace forward

}  // namespace template_2nd

#endif /* SRC_TEMPLATE_CHP11_FOREACH_HPP_ */
