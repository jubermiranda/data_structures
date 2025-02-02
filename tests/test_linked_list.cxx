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

TEST(LinkedListTest, PopFront){
  MY_DS::LinkedList<int> list;

  list.push_front(2);
  list.push_front(3);
  list.push_front(5);
  list.push_front(7);
  list.push_front(11);
  ASSERT_EQ(list.size(), 5);
  EXPECT_EQ(list.front(), 11);

  list.pop_front();
  EXPECT_EQ(list.front(), 7);
  list.pop_front();
  EXPECT_EQ(list.front(), 5);
  list.pop_front();
  EXPECT_EQ(list.front(), 3);
  list.pop_front();
  EXPECT_EQ(list.front(), 2);
}

TEST(LinkedListTest, PopBack){
  MY_DS::LinkedList<int> list;

  list.push_front(2);
  list.push_front(3);
  list.push_front(5);
  list.push_front(7);
  list.push_front(11);
  ASSERT_EQ(list.size(), 5);
  EXPECT_EQ(list.back(), 2);

  list.pop_back();
  EXPECT_EQ(list.back(), 3);
  list.pop_back();
  EXPECT_EQ(list.back(), 5);
  list.pop_back();
  EXPECT_EQ(list.back(), 7);
  list.pop_back();
  EXPECT_EQ(list.back(), 11);
}
