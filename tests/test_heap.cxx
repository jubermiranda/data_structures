#include "heap/heap.h"

#include <gtest/gtest.h>


TEST(MaxHeapTree, CheckStatusAfterCreation) {
  MY_DS::heap<int> heap;
  ASSERT_EQ(heap.size(), 0);
  ASSERT_TRUE(heap.is_empty());
}

TEST(MaxHeapTree, CheckSizeAfterInsertion) {
  MY_DS::heap<int> heap;
  heap.insert(10);
  ASSERT_EQ(heap.size(), 1);
  heap.insert(20);
  ASSERT_EQ(heap.size(), 2);
}

TEST(MaxHeapTree, CheckIsEmptyAfterInsertion) {
  MY_DS::heap<int> heap;
  ASSERT_TRUE(heap.is_empty());
  heap.insert(10);
  ASSERT_FALSE(heap.is_empty());
}

TEST(MaxHeapTree, CheckSizeAfterMultipleInsertions) {
  MY_DS::heap<int> heap;
  ASSERT_EQ(heap.size(), 0);

  for (int i = 0; i < 10; ++i) {
    heap.insert(i);
    EXPECT_EQ(heap.size(), i + 1);
  }

  ASSERT_EQ(heap.size(), 10);
}

TEST(MaxHeapTree, CheckPeekFunctionality) {
  MY_DS::heap<int> heap;
  heap.insert(10);
  ASSERT_EQ(heap.peek(), 10);

  heap.insert(20);
  ASSERT_EQ(heap.peek(), 20);

  heap.insert(15);
  ASSERT_EQ(heap.peek(), 20);
}
