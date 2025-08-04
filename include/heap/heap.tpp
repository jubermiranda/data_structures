#pragma once

#include "heap.h"
#include <cstddef>
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
heap<Data, Order>::heap(const heap &other) :
heap_tree(nullptr), crr_height(other.crr_height), crr_pos(other.crr_pos)
{
  if(other.is_empty()){
    this->expand_heap();
    return;
  }

  this->heap_tree = new Data*[this->crr_height +1];
  for(size_t i = 0; i < this->crr_height-1 ; i++){
    this->heap_tree[i] = new Data[pow_two(i)];
    for(size_t j = 0; j < pow_two(i); j++){
      this->heap_tree[i][j] = other.heap_tree[i][j];
    }
  }
  this->heap_tree[this->crr_height] = new Data[pow_two(this->crr_height)];
  for(size_t j = 0; j < this->crr_pos; j++){
    this->heap_tree[this->crr_height][j] = other.heap_tree[this->crr_height][j];
  }
}

template <typename Data, typename Order>
heap<Data, Order>::heap(heap &&other) noexcept :
  heap_tree(other.heap_tree), 
  crr_height(other.crr_height), 
  crr_pos(other.crr_pos)
{
  other.heap_tree = nullptr;
  other.crr_height = 0;
  other.crr_pos = 0;
}

template <typename Data, typename Order>
heap<Data, Order>& heap<Data, Order>::operator=(const heap &other) {
  if(this != &other){
    heap<Data, Order> temp(other);
    std::swap(*this, temp);
  }
  return *this;
}

template <typename Data, typename Order>
heap<Data, Order>& heap<Data, Order>::operator=(heap &&other) noexcept {
  if(this != &other){
    this->clear();
    std::swap(*this, other);
  }
  return *this;
}

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
  throw std::runtime_error("not implemented");
}

template <typename Data, typename Order>
heap<Data, Order>::~heap(){
  this->clear();
}

template <typename Data, typename Order>
void heap<Data, Order>::insert(const Data &item){
  if(this->is_empty() && this->heap_tree == nullptr){
    this->expand_heap();
  } else if(this->hasnt_space()){
    this->expand_heap();
    this->crr_pos = 0;
  }

  this->heap_tree[this->crr_height][this->crr_pos++] = item;
  this->float_up(this->crr_height, this->crr_pos - 1);
}

template <typename Data, typename Order>
Data heap<Data, Order>::extract(){
  if(this->is_empty()){
    throw std::runtime_error("Heap is empty, cannot extract");
  }

  Data extracted_item = this->heap_tree[0][0];
  this->process_removal();
  this->sink_down(0, 0);
  return extracted_item;
}

template <typename Data, typename Order>
const Data& heap<Data, Order>::peek() const{
  if(this->is_empty()){
    throw std::runtime_error("Heap is empty, cannot peek");
  }
  return this->heap_tree[0][0];
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
  this->heap_tree = nullptr;
  this->crr_height = 0;
  this->crr_pos = 0;
}


// -- private


template <typename Data, typename Order>
bool heap<Data, Order>::hasnt_space() const{
  return (this->crr_pos >= pow_two(this->crr_height));
}

template <typename Data, typename Order>
void heap<Data, Order>::float_up(size_t h, size_t pos) {
  if(h == 0){
    return;
  }
  size_t parent_pos = (pos) / 2;
  if(Order()(this->heap_tree[h-1][parent_pos], this->heap_tree[h][pos])){
    std::swap(this->heap_tree[h][pos], this->heap_tree[h-1][parent_pos]);
    this->float_up(h-1, parent_pos);
  }
}

template <typename Data, typename Order>
void heap<Data, Order>::sink_down(size_t h, size_t pos) {
  if(h >= this->crr_height){
    return;
  }

  size_t left_child = pos * 2;
  size_t right_child = pos * 2 + 1;
  size_t to_sink;

  if(left_child >= crr_pos)
    return;
  if(right_child >= crr_pos)
    to_sink = left_child;
  else {
    if(Order()(heap_tree[h][left_child], heap_tree[h][right_child])){
      to_sink = right_child;
    } else {
      to_sink = left_child;
    }
  }

  if(Order()(heap_tree[h][pos], heap_tree[h+1][to_sink])){
    std::swap(heap_tree[h][pos], heap_tree[h+1][to_sink]);
    this->sink_down(h+1, to_sink);
  }
}

template <typename Data, typename Order>
void heap<Data, Order>::process_removal() {
  if(this->is_empty()){
    return;
  }

  // Move last element to root and remove last element
  size_t last_h, last_pos;
  if(crr_pos > 0){
    last_h = crr_height;
    last_pos = --crr_pos;
  } else {
    last_h = crr_height - 1;
    last_pos = pow_two(last_h) - 1;

    crr_pos = last_pos;
    delete[] heap_tree[crr_height];
    heap_tree[crr_height--] = nullptr;
  }
  heap_tree[0][0] = heap_tree[last_h][last_pos];
}

template <typename Data, typename Order>
void heap<Data, Order>::expand_heap() {
  if(this->is_empty() && this->heap_tree == nullptr){
    this->heap_tree = new Data*[1];
    this->heap_tree[0] = new Data[1];

  } else {
    if(this->size() < this->calc_max_size()){
      // dont expand if there is still space
      return;
    }
    size_t new_height = this->crr_height + 1;
    if(new_height > MAX_HEIGHT){
      throw std::runtime_error("Heap height exceeds maximum allowed height");
    }

    this->crr_height = new_height;
    Data **new_tree = new Data*[new_height+1];
    for(size_t i = 0; i < new_height; i++){
      new_tree[i] = this->heap_tree[i];
    }
    new_tree[new_height] = new Data[pow_two(new_height)];

    if(this->heap_tree != nullptr){
      delete[] this->heap_tree;
    }
    this->heap_tree = new_tree;
  }
}

template <typename Data, typename Order>
size_t heap<Data, Order>::calc_max_size() const {
  return sum_of_pow_two(this->crr_height);
}

template <typename Data, typename Order>
void heap<Data, Order>::print(std::ostream &os) const {
    if (is_empty()) {
      os << "[EMPTY]";
      return;
    }
    os << "Max size : " << this->calc_max_size() << std::endl
        << "crr size: " << this->size() << std::endl
        << "crr height: " << this->crr_height << std::endl
        << "Elements: " << std::endl;

    for (size_t h = 0; h < crr_height; h++) {
      for(size_t i = 0; i < pow_two(h); i++) {
        os << "[" << heap_tree[h][i] << "]";
      }
      os << std::endl;
    }
    for(size_t i = 0; i < crr_pos; i++) {
      os << "[" << heap_tree[crr_height][i] << "]";
    }
    os << std::endl << "----" << std::endl;
}

};
