#include <list>
using namespace MY_DS;

template <typename T> void OrdList<T>::insert(const T& item){
  typename std::list<T>::iterator iter = data.begin();

  while(iter != data.end() && *iter < item)
    ++iter;
  data.insert(iter, item);
}

template <typename T> void OrdList<T>::remove(const T& item){
  data.remove(item);
}

template <typename T> size_t OrdList<T>::size() const{
  return data.size();
}

template <typename T> typename OrdList<T>::const_iterator OrdList<T>::begin() const{
  return data.begin();
}

template <typename T> typename OrdList<T>::const_iterator OrdList<T>::end() const{
  return data.end();
}

