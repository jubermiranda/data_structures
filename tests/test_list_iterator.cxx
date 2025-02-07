#include "list_iter/list.h"

#include <gtest/gtest.h>

TEST(ListIteratorTest, InitialTest) {
  MY_DS::List<int> list;
  ASSERT_NE(list, nullptr);

}
