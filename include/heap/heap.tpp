#pragma once

#include "heap.h"
#include <stdexcept>
#include <vector>

size_t pow_two(size_t n){
  return 1 << n;
}

size_t sum_of_pow_two(size_t n){
  return (pow_two(n+1) -1);
}

namespace MY_DS {

template <typename Data, typename Order>
heap<Data, Order>::heap() :
  heap_tree(nullptr), crr_height(0), crr_pos(0)
{
   this->expand_heap();
}

template <typename Data, typename Order>
heap<Data, Order>::heap(std::vector<Data>) :
  heap_tree(nullptr), crr_height(0), crr_pos(0)
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
  if( this->crr_height == 0 && this->crr_pos == 0){
    return 0;
  }

  size_t max_size = this->calc_max_size();
  size_t remaining_nodes = pow_two(this->crr_height) - this->crr_pos;

  return max_size - remaining_nodes;
}

template <typename Data, typename Order>
bool heap<Data, Order>::is_empty() const{
  return (this->crr_height == 0 && this->crr_pos == 0);
}

template <typename Data, typename Order>
void heap<Data, Order>::clear() {
  if(this->is_empty())
    return;

  for(int i=0; i < this->crr_height; i++){
    delete[] this->heap_tree[i];
  }
  delete[] this->heap_tree;
}


// -- private
template <typename Data, typename Order>
void heap<Data, Order>::expand_heap() {
  if(this->is_empty()){
    this->heap_tree = new Data*[1];
    this->heap_tree[0] = new Data[1];
  } else {
    throw new std::runtime_error("not implemented");
  }
}

template <typename Data, typename Order>
size_t heap<Data, Order>::calc_max_size() const {
  return sum_of_pow_two(this->crr_height);
}

};
