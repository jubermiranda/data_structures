#include "stack.h"

#include <gtest/gtest.h>

TEST(LinkedStackTest, IsEmptyOnCreate) {
  MY_DS::Stack<int> stack;

  EXPECT_TRUE(stack.is_empty());
  EXPECT_EQ(stack.size(), 0);
}
