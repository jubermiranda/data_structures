#include "b_tree/b_tree.h"

#include <gtest/gtest.h>

using namespace MY_DS;

TEST(BinaryTreeTest, EmptyTree) {
  b_tree<int> tree = b_tree<int>();
  EXPECT_TRUE(tree.is_empty());
}

TEST(BinaryTreeTest, NonEmptyTree) {
  b_tree<int> tree;
  tree.insert(41); // + 1
  EXPECT_FALSE(tree.is_empty());
}

TEST(BinaryTreeTest, InsertAndCheckData) {
  b_tree<int> tree;
  tree.insert(4);
  EXPECT_EQ(tree.get_data(), 4);

  tree.insert(2);
  EXPECT_EQ(tree.get_left_subtree().get_data(), 2);

  tree.insert(6);
  EXPECT_EQ(tree.get_right_subtree().get_data(), 6);
}

TEST(BinaryTreeTest, InsertAndSize) {
  b_tree<int> tree;
  EXPECT_EQ(tree.size(), 0);

  tree.insert(4);
  EXPECT_EQ(tree.size(), 1);

  tree.insert(2);
  EXPECT_EQ(tree.size(), 2);
}

TEST(BinaryTreeTest, IsLeaf) {
  b_tree<int> tree;
  tree.insert(4);
  EXPECT_TRUE(tree.is_leaf());

  tree.insert(2);
  EXPECT_FALSE(tree.is_leaf());

  tree.insert(6);
  EXPECT_FALSE(tree.is_leaf());
  EXPECT_TRUE(tree.get_left_subtree().is_leaf());
  EXPECT_TRUE(tree.get_right_subtree().is_leaf());

  tree.get_left_subtree().insert(1);
  EXPECT_FALSE(tree.get_left_subtree().is_leaf());
  EXPECT_TRUE(tree.get_left_subtree().get_left_subtree().is_leaf());
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

  EXPECT_EQ(oss.str(), "1\n2\n3\n4\n5\n6\n7\n");
}

TEST(BinaryTreeTest, PrintModifiersWithBtreeInt) {
  b_tree<int> tree;
  tree.insert(4);
  tree.insert(2);
  tree.insert(6);
  tree.insert(1);
  tree.insert(3);
  tree.insert(5);
  tree.insert(7);
  std::ostringstream rhs;

  rhs.str("");
  rhs << MY_DS::pre_order << tree;
  EXPECT_EQ(rhs.str(), "4\n2\n1\n3\n6\n5\n7\n");

  rhs.str("");
  rhs << MY_DS::order << tree;
  EXPECT_EQ(rhs.str(), "1\n2\n3\n4\n5\n6\n7\n");

  rhs.str("");
  rhs << MY_DS::post_order << tree;
  EXPECT_EQ(rhs.str(), "1\n3\n2\n5\n7\n6\n4\n");
}

TEST(BinaryTreeTest, PrintModifiersWithBtreeString) {
  b_tree<std::string> tree;

  tree.insert("disco");
  tree.insert("blueberry");
  tree.insert("apple");
  tree.insert("cherry"); tree.insert("fig");
  tree.insert("grape");
  tree.insert("espresso");

  std::ostringstream oss;

  oss << MY_DS::pre_order << tree;
  EXPECT_EQ(oss.str(), "disco\nblueberry\napple\ncherry\nfig\nespresso\ngrape\n");
  oss.str("");

  oss << MY_DS::order << tree;
  EXPECT_EQ(oss.str(), "apple\nblueberry\ncherry\ndisco\nespresso\nfig\ngrape\n");
  oss.str("");

  oss << MY_DS::post_order << tree;
  EXPECT_EQ(oss.str(), "apple\ncherry\nblueberry\nespresso\ngrape\nfig\ndisco\n");
}

// -- Helper functions

