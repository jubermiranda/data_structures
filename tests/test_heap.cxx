#include "heap/heap.h"

#include <gtest/gtest.h>


TEST(MaxHeapTree, CheckSizeAfterCreation) {
  MY_DS::heap<int> heap;
  ASSERT_EQ(heap.size(), 0);
}

TEST(MaxHeapTree, CheckSizeAfterInsertion) {
  MY_DS::heap<int> heap;
  heap.insert(10);
  ASSERT_EQ(heap.size(), 1);
  heap.insert(20);
  ASSERT_EQ(heap.size(), 2);
}
