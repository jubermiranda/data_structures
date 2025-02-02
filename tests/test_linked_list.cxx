#include "linked_list.h"

#include <gtest/gtest.h>

TEST(LinkedListTest, IsEmptyOnCreate) {
  MY_DS::LinkedList<int> list;

  EXPECT_TRUE(list.is_empty());
  EXPECT_EQ(list.size(), 0);
}
