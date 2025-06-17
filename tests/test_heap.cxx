#include "heap/heap.h"

#include <gtest/gtest.h>


TEST(MaxHeapTree, CheckSizeAfterCreation) {
  MY_DS::heap<int> heap;
  ASSERT_EQ(heap.size(), 0);
}
