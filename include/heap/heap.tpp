#pragma once

#include "heap.h"
#include <stdexcept>
#include <vector>

namespace MY_DS {

template <typename Data, typename Order>
heap<Data, Order>::heap() :
  heap_tree(nullptr), height(0), crr_pos(0)
{
   this->expand_heap();
}

template <typename Data, typename Order>
heap<Data, Order>::heap(std::vector<Data>) :
  heap_tree(nullptr), height(0), crr_pos(0)
{
  throw new std::runtime_error("not implemented");
}

template <typename Data, typename Order>
heap<Data, Order>::~heap(){
  this->clear();
}

template <typename Data, typename Order>
void heap<Data, Order>::insert(const Data &item){
  throw new std::runtime_error("not implemented");
}

template <typename Data, typename Order>
Data heap<Data, Order>::extract(){
  throw new std::runtime_error("not implemented");
}

template <typename Data, typename Order>
const Data& heap<Data, Order>::peek() const{
  throw new std::runtime_error("not implemented");
}

template <typename Data, typename Order>
size_t heap<Data, Order>::size() const{
  throw new std::runtime_error("not implemented");
}

template <typename Data, typename Order>
bool heap<Data, Order>::is_empty() const{
  throw new std::runtime_error("not implemented");
}

template <typename Data, typename Order>
void heap<Data, Order>::clear() {
  throw new std::runtime_error("not implemented");
}


// -- private
template <typename Data, typename Order>
void heap<Data, Order>::expand_heap() {
  throw new std::runtime_error("not implemented");
}

};
