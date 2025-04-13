#include "ordered_list/ordered_list.h"

#include <gtest/gtest.h>

TEST(OrderedListTest, Size) {
  MY_DS::OrdList<int> list;
  ASSERT_EQ(list.size(), 0);

  list.insert(4);
  ASSERT_EQ(list.size(), 1);
  list.insert(2);
  ASSERT_EQ(list.size(), 2);
}
