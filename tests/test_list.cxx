#include <gtest/gtest.h>
#include <string>

#include "list.h"

using std::string;

TEST(ListTest, CreateList) {
  MY_DS::List<int> my_list;
  EXPECT_EQ(my_list.size(), 0);
  EXPECT_TRUE(my_list.is_empty());
}

TEST(ListTest, PushElements) {
  MY_DS::List<int> my_list;

  EXPECT_EQ(my_list.size(), 0);
  my_list.push(4);
  my_list.push(2);
  EXPECT_EQ(my_list.size(), 2);
  my_list.push(3);
  my_list.push(1);
  EXPECT_EQ(my_list.size(), 4);
}
