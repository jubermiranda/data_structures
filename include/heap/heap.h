#pragma once

#include <cstddef>
#include <functional>
#include <ostream>
#include <vector>

namespace MY_DS {

const int MAX_HEIGHT = 32;

template <typename Data, typename Order = std::less<Data>> 
class heap {
public:
  heap(const heap&);
  heap(heap&&) noexcept;
  heap& operator=(const heap&);
  heap& operator=(heap&&) noexcept;
  ~heap();

  heap();
  heap(std::vector<Data>);

  void insert (const Data&);
  Data extract ();
  const Data& peek() const;

  size_t size() const;
  bool is_empty() const;

  void clear();

  friend void swap(heap &a, heap &b) noexcept {
    using std::swap;
    swap(a.heap_tree, b.heap_tree);
    swap(a.crr_height, b.crr_height);
    swap(a.crr_pos, b.crr_pos);
  }

  void print(std::ostream &os) const;
  

private:
  Data **heap_tree;
  size_t crr_height;
  size_t crr_pos;

  void expand_heap();
  size_t calc_max_size () const;
  bool hasnt_space() const;
  void float_up(size_t h, size_t pos);
  void sink_down(size_t h, size_t pos);
  void process_removal();
};

};

#include "heap.tpp"
