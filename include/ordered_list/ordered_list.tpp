#include "ordered_list/ordered_list.h"

#include <list>

using namespace MY_DS;

template <typename T> void OrdList<T>::insert_from_begin(const T &item) {
  typename std::list<T>::iterator iter = data.begin();

  while (iter != data.end() && *iter < item)
    ++iter;
  data.insert(iter, item);
}

template <typename T> void OrdList<T>::insert_from_end(const T &item) {
  typename std::list<T>::iterator iter = data.end();

  do
    --iter;
  while (iter != data.begin() && *iter > item);

  if (item < *iter)
    data.insert(iter, item);
  else
    data.insert(++iter, item);
}

template <typename T> void OrdList<T>::insert(const T &item) {
  insert_from_begin(item);
}

template <typename T> void OrdList<T>::remove(const T &item) {
  data.remove(item);
}

template <typename T> size_t OrdList<T>::size() const { return data.size(); }

template <typename T>
typename OrdList<T>::const_iterator OrdList<T>::begin() const {
  return data.begin();
}

template <typename T>
typename OrdList<T>::const_iterator OrdList<T>::end() const {
  return data.end();
}

int middle_value(int begin, int end){
  return (end-begin)/2;
}
