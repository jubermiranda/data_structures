#pragma once

#include <functional>
#include <vector>

namespace MY_DS {

const int MAX_HEIGHT = 32;

template <typename Data, typename Order = std::less<Data>> 
class heap {
public:
  ~heap();
  heap();
  heap(std::vector<Data>);

  void insert (const Data&);
  Data extract ();
  const Data& peek() const;

  size_t size() const;
  bool is_empty() const;

  void clear();

private:
  Data **heap_tree;
  size_t crr_height;
  size_t crr_pos;

  void expand_heap();
  size_t calc_max_size () const;
};

};

#include "heap.tpp"
