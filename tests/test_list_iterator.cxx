#include "list_iter/list.h"

#include <gtest/gtest.h>

TEST(ListIteratorTest, SizeZeroOnCreate) {
  MY_DS::List<int> list;
  ASSERT_EQ(list.size(), 0);
}

TEST(ListIteratorTest, SizeIncreaseDecrease) {
  MY_DS::List<int> list;

  list.push_back(4);
  ASSERT_EQ(list.size(), 1);
  list.push_back(2);
  ASSERT_EQ(list.size(), 2);

  list.pop_back();
  ASSERT_EQ(list.size(), 1);
  list.pop_back();
  ASSERT_EQ(list.size(), 0);
}

