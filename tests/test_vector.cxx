#include <gtest/gtest.h>
#include <string>

#include "vector.h"

using std::string;

TEST(VectorTest, CreateVector) {
  MY_DS::Vector<int> my_vec;
  EXPECT_EQ(my_vec.size(), 0);
}


TEST(VectorTest, PushPopBack) {
  MY_DS::Vector<int> my_vec(4);
  EXPECT_EQ(my_vec.size(), 0);

  my_vec.push_back(4);
  EXPECT_EQ(my_vec.size(), 1);

  my_vec.push_back(2);
  EXPECT_EQ(my_vec.size(), 2);

  my_vec.pop_back();
  EXPECT_EQ(my_vec.size(), 1);

  my_vec.pop_back();
  EXPECT_EQ(my_vec.size(), 0);

  my_vec.pop_back();
  EXPECT_EQ(my_vec.size(), 0);
}
