#pragma once

#include <cstddef>
#include <string>

#include "node.h"

namespace MY_DS {

enum class tree_print_mode {
  ORDER,
  PRE_ORDER,
  POST_ORDER
};

struct print_mode {
  tree_print_mode mode;
};

inline print_mode pre_order { tree_print_mode::PRE_ORDER };
inline print_mode order { tree_print_mode::ORDER };
inline print_mode post_order { tree_print_mode::POST_ORDER };
inline int print_mode_index();
inline std::ostream &operator<<(std::ostream &, print_mode);
inline tree_print_mode get_print_mode(std::ostream &);


template <typename Data> class b_tree {
protected:
  BTNode<Data> *root;
  b_tree(BTNode<Data> *root) : root(root) {}

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
  virtual std::string to_string(
      tree_print_mode mode = tree_print_mode::ORDER
  ) const;

  size_t size() const;

  void clear();


private:
  size_t size_of_tree(const b_tree<Data>&) const;
};

template<typename Data> std::ostream& operator<<(
    std::ostream& out,const b_tree<Data>& tree
){
  return out << tree.to_string(get_print_mode(out));
}

// -- print mode functions

inline int print_mode_index(){
  static int index = std::ios_base::xalloc();
  return index;
}

inline std::ostream &operator<<(std::ostream &os, print_mode mode) {
    os.iword(print_mode_index()) = static_cast<long>(mode.mode);
    return os;
}

inline tree_print_mode get_print_mode(std::ostream &os) {
  return static_cast<tree_print_mode>(os.iword(print_mode_index()));
}

}; // namespace MY_DS
#include "b_tree.tpp"
