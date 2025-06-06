#include "b_tree/b_tree.h"

#include <gtest/gtest.h>

using namespace MY_DS;

TEST(BinaryTreeTest, EmptyTree) {
  b_tree<int> tree = b_tree<int>();
  EXPECT_TRUE(tree.empty());
}

TEST(BinaryTreeTest, InsertAndSize) {
  b_tree<int> tree;
  EXPECT_EQ(tree.size(), 0);

  tree.insert(4);
  EXPECT_EQ(tree.size(), 1);

  tree.insert(2);
  EXPECT_EQ(tree.size(), 2);
}
