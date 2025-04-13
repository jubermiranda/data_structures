#include "ordered_list/ordered_list.h"

#include <gtest/gtest.h>
#include <random>

const size_t TEST_LIST_SIZE = 1993;

void fill_list_rand_positive_int(
    MY_DS::OrdList<int> &,
    size_t amount,
    size_t max
);

TEST(OrderedListTest, Size) {
  MY_DS::OrdList<int> list;
  ASSERT_EQ(list.size(), 0);

  list.insert(4);
  ASSERT_EQ(list.size(), 1);
  list.insert(2);
  ASSERT_EQ(list.size(), 2);
}

TEST(OrderedListTest, EdgesInsert) {
  MY_DS::OrdList<int> list;
  size_t max_value = 65535;

  fill_list_rand_positive_int(list, TEST_LIST_SIZE, max_value);
  ASSERT_EQ(list.size(), TEST_LIST_SIZE);
  ASSERT_TRUE(*(list.begin()) >= 0);
  ASSERT_TRUE(*(--list.end()) <= max_value);

  list.insert(-1);
  EXPECT_EQ(list.size(), TEST_LIST_SIZE + 1);
  EXPECT_EQ(*(list.begin()), -1);

  list.insert(max_value+1);
  EXPECT_EQ(list.size(), TEST_LIST_SIZE + 2);
  EXPECT_EQ(*(--list.end()), max_value+1);
}

void fill_list_rand_positive_int(
    MY_DS::OrdList<int> &list,
    size_t amount,
    size_t max
) {

  std::random_device rand_d;
  std::mt19937 gen(rand_d());
  std::uniform_int_distribution<uint32_t> dist(0, max);

  for (int i = 0; i < amount; i++)
    list.insert(dist(gen));
}
