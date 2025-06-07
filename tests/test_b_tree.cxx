#include "b_tree/b_tree.h"

#include <gtest/gtest.h>

using namespace MY_DS;

TEST(BinaryTreeTest, EmptyTree) {
  b_tree<int> tree = b_tree<int>();
  EXPECT_TRUE(tree.is_empty());
}

TEST(BinaryTreeTest, InsertAndSize) {
  b_tree<int> tree;
  EXPECT_EQ(tree.size(), 0);

  tree.insert(4);
  EXPECT_EQ(tree.size(), 1);

  tree.insert(2);
  EXPECT_EQ(tree.size(), 2);
}

TEST(BinaryTreeTest, PrintBtreeAfterInserts) {
  b_tree<int> tree;
  tree.insert(4);
  tree.insert(2);
  tree.insert(6);
  tree.insert(1);
  tree.insert(3);
  tree.insert(5);
  tree.insert(7);

  std::ostringstream oss;
  oss << tree;

  EXPECT_EQ(oss.str(), "4\n2\n1\n3\n6\n5\n7\n");
}
