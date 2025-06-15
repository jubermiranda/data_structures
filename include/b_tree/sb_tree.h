#pragma once

#include "node.h"
#include "b_tree.h"

namespace MY_DS{

template <typename Data>class sb_tree : public b_tree<Data> {
public:
  sb_tree<Data>() : b_tree<Data>(){}

  virtual bool insert(const Data &data);
  virtual bool erase(const Data &data);
  const Data* find(const Data& target) const;

private:
  virtual bool insert(BTNode<Data>*& crr_root, const Data& target);
  virtual bool erase(BTNode<Data>*& crr_root, const Data& target);
  const Data*  find(BTNode<Data>* crr_root, const Data& target) const;

  BTNode<Data> *& find_replacement(BTNode<Data>*&);
};

};

#include "sb_tree.tpp"
