#include <gtest/gtest.h>
#include <string>

#include "vector.h"

using std::string;

TEST(VectorTest, CreateVector) {
  MY_DS::Vector<int> my_vec;
  EXPECT_EQ(my_vec.size(), 0);
}

TEST(VectorTest, TypeIntPushPopBack) {
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

TEST(VectorTest, TypeStringPushPopBack) {
  MY_DS::Vector<string> my_vec(4);
  EXPECT_EQ(my_vec.size(), 0);

  my_vec.push_back("test");
  EXPECT_EQ(my_vec.size(), 1);

  my_vec.push_back("another test");
  EXPECT_EQ(my_vec.size(), 2);

  my_vec.pop_back();
  EXPECT_EQ(my_vec.size(), 1);

  my_vec.pop_back();
  EXPECT_EQ(my_vec.size(), 0);

  my_vec.pop_back();
  EXPECT_EQ(my_vec.size(), 0);
}

TEST(VectorTest, TypeClassPushPopBack) {
  class Test {
  public:
    Test(int n, string t) : num(n), text(t) {}
    Test() : num(0), text("") {}

    int num;
    string text;
  };

  MY_DS::Vector<Test> my_vec(4);
  EXPECT_EQ(my_vec.size(), 0);

  my_vec.push_back(Test(4, "four"));
  EXPECT_EQ(my_vec.size(), 1);
  my_vec.push_back(Test(2, "two"));
  EXPECT_EQ(my_vec.size(), 2);


  my_vec.pop_back();
  EXPECT_EQ(my_vec.size(), 1);
  my_vec.pop_back();
  EXPECT_EQ(my_vec.size(), 0);
}
