#ifndef LINKED_H_
#define LINKED_H_

#include "node.h"
#include <cstddef>

namespace MY_DS {

template <typename T> class LinkedList {
private:
  Node<T> *root;
  size_t crr_size;

public:
  LinkedList();
  ~LinkedList();

  void push_front(const T &value);
  void push_back(const T &value);
  void pop_front();
  void pop_back();

  T front() const;
  T back() const;

  bool is_empty() const;
  size_t size() const;

  void clear();
};

} // namespace MY_DS

// IMPL
#include "linked_list.tpp"

#endif // LINKED_H_
