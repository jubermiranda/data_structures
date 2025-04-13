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

TEST(ListIteratorTest, PushBackInt) {
  MY_DS::List<int> list;

  list.push_back(4);
  ASSERT_EQ(list.back(), 4);
  list.push_back(2);
  ASSERT_EQ(list.back(), 2);
  list.push_back(0);
  ASSERT_EQ(list.back(), 0);

  list.pop_back();
  ASSERT_EQ(list.back(), 2);
}

TEST(ListIteratorTest, PushBackString) {
  MY_DS::List<std::string> list;

  list.push_back("list");
  ASSERT_EQ(list.back(), "list");
  list.push_back("iterator");
  ASSERT_EQ(list.back(), "iterator");
  list.push_back("str");
  ASSERT_EQ(list.back(), "str");

  list.pop_back();
  ASSERT_EQ(list.back(), "iterator");
}

class TestObj {
public:
  int n;
  std::string s;
  double d;
};

TEST(ListIteratorTest, PushBackObj) {
  MY_DS::List<TestObj> list;
  TestObj obj1;

  obj1.n = 1;
  obj1.d = 2.4;
  obj1.s = "test1";
  list.push_back(obj1);

  ASSERT_EQ(list.back().n, 1);
  ASSERT_EQ(list.back().d, 2.4);
  ASSERT_EQ(list.back().s, "test1");


  obj1.n = 99;
  obj1.d = 0.0001;
  obj1.s = "test2";
  list.push_back(obj1);

  ASSERT_EQ(list.back().n, 99);
  ASSERT_EQ(list.back().d, 0.0001);
  ASSERT_EQ(list.back().s, "test2");

  list.pop_back();

  ASSERT_EQ(list.back().n, 1);
  ASSERT_EQ(list.back().d, 2.4);
  ASSERT_EQ(list.back().s, "test1");
}

TEST(ListIteratorTest, PushFrontInt) {
  //TODO
}
