#pragma once

#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>

#include "node.h"

namespace MY_DS {

template <typename Data> class b_tree {
private:
  BTNode<Data> *root;

public:
  b_tree() : root(nullptr) {}
  b_tree(
      const Data &data,
      const b_tree<Data> &left = b_tree<Data>(),
      const b_tree<Data> &right = b_tree<Data>()
  ) : root(new BTNode<Data>(data, left.root, right.root)) {};
  virtual ~b_tree() {}

  b_tree<Data> get_left_subtree() const;
  b_tree<Data> get_right_subtree() const;

  const Data &get_data() const;

  bool is_empty() const;
  bool is_leaf() const;
  virtual std::string to_string() const;

  size_t size() const;
  size_t height() const;

  void insert(const Data &data);
  void remove(const Data &data);
  void clear();

  BTNode<Data> *find(const Data &data) const;

protected:
  b_tree(BTNode<Data> *root) : root(root) {}

private:
  size_t get_node_height(BTNode<Data> *node) const;
};

template<typename Data> std::ostream& operator<<(
    std::ostream& out,
    const b_tree<Data>& tree
) {
  return out << tree.to_string();
}


}; // namespace MY_DS
#include "b_tree.tpp"
