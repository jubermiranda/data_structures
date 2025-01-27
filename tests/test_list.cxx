#include <gtest/gtest.h>
#include <string>

#include "list.h"

using std::string;

TEST(ListTest, CreateList) {
  MY_DS::List<int> my_list;
  EXPECT_EQ(my_list.size(), 0);
  EXPECT_TRUE(my_list.is_empty());
}
