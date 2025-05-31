#pragma once

#include "node.h"
#include <cstddef>

namespace MY_DS {

  template <typename T> class Stack {
  private:
    Node<T> *stack_top;
    size_t crr_size;

  public:
    Stack();
    ~Stack();

    const T top() const;

    void push(T data);
    T pop();

    bool is_empty() const;
    size_t size() const;

    void clear();
  };

} // namespace MY_DS

// IMPL
#include "stack.tpp"
