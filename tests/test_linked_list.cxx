#include "linked_list.h"

#include <gtest/gtest.h>

TEST(LinkedListTest, IsEmptyOnCreate) {
  MY_DS::LinkedList<int> list;

  EXPECT_TRUE(list.is_empty());
  EXPECT_EQ(list.size(), 0);
}


TEST(LinkedListTest, PushBackFront){
  MY_DS::LinkedList<int> list;
  ASSERT_EQ(list.size(), 0);

  list.push_back(7);
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.back(), 7);
  EXPECT_EQ(list.front(), 7);

  list.push_back(14);
  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(list.back(), 14);
  EXPECT_EQ(list.front(), 7);

  list.push_back(21);
  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(list.back(), 21);
  EXPECT_EQ(list.front(), 7);

  //

  MY_DS::LinkedList<int> list2;

  list2.push_front(11);
  EXPECT_EQ(list2.size(), 1);
  EXPECT_EQ(list2.back(), 11);
  EXPECT_EQ(list2.front(), 11);

  list2.push_front(22);
  EXPECT_EQ(list2.size(), 2);
  EXPECT_EQ(list2.back(), 11);
  EXPECT_EQ(list2.front(), 22);

  list2.push_front(33);
  EXPECT_EQ(list2.size(), 3);
  EXPECT_EQ(list2.back(), 11);
  EXPECT_EQ(list2.front(), 33);
}
