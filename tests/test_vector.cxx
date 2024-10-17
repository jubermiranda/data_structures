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

TEST(VectorTest, IsEmptyWorks) {
  MY_DS::Vector<int> my_vec;
  EXPECT_TRUE(my_vec.is_empty());

  my_vec.push_back(1);
  EXPECT_FALSE(my_vec.is_empty());
}

TEST(VectorTest, SwapVectors) {
  MY_DS::Vector<int> vec1;
  MY_DS::Vector<int> vec2;

  vec1.push_back(2);
  vec1.push_back(2);
  vec1.push_back(2);
  vec1.push_back(2);

  vec2.push_back(4);
  vec2.push_back(4);


  EXPECT_EQ(vec1.size(), 4);
  EXPECT_EQ(vec2.size(), 2);

  vec1.swap(vec2);

  EXPECT_EQ(vec1.size(), 2);
  EXPECT_EQ(vec2.size(), 4);
}

TEST(VectorTest, ResizeVector) {
  MY_DS::Vector<int> my_vec(4);

  EXPECT_EQ(my_vec.max_size(), 4);
  my_vec.resize(2);
  EXPECT_EQ(my_vec.max_size(), 2);
}


TEST(VectorTest, RandAcessElement) {
  //
}
