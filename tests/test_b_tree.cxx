#include "b_tree/b_tree.h"

#include <gtest/gtest.h>

using namespace MY_DS;

TEST(BinaryTreeTest, EmptyTree) {
  b_tree<int> tree = b_tree<int>();
  EXPECT_TRUE(tree.empty());
}
