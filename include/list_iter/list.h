#pragma once

#include <cstddef>
#include "iterator.h"

namespace MY_DS {

template <typename T> class List {
private:
#include "../node.h"
public:
  friend class iterator<T>;

private:
  DNode<T> *head;
  DNode<T> *tail;
  size_t num_items;

public:
  List();
  List(const List<T> &other);
  List<T> &operator=(const List<T> &other);
  ~List();

  void push_front(const T &item);
  void push_back(const T &item);
  void pop_front();
  void pop_back();
  iterator<T> insert(iterator<T> pos, const T &item);
  iterator<T> erase(iterator<T> pos);

  T& front();
  const T& front() const;
  T& back();
  const T& back() const;
  iterator<T> begin();
  const_iterator<T> begin() const;
  iterator<T> end();
  const_iterator<T> end() const;

  void swap(List<T> other);
  bool is_empty() const;
  size_t size() const;

  void clear();

  bool operator==(const List<T>&) const ;
  bool operator==(void *) const ;
  bool operator!=(const List<T>&) const ;
  bool operator!=(void *) const ;

};

#include "list_iter/list.tpp"

} // namespace MY_DS


