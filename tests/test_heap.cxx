#include "heap/heap.h"

#include <gtest/gtest.h>

class MaxHeapTestFixture : public ::testing::Test {
protected:
  void SetUp() override {
  }

  void TearDown() override {
  }
};

TEST_F(MaxHeapTestFixture, CheckStatusAfterCreation) {
  MY_DS::heap<int> heap;
  ASSERT_EQ(heap.size(), 0);
  ASSERT_TRUE(heap.is_empty());
}

TEST_F(MaxHeapTestFixture, CheckSizeAfterInsertion) {
  MY_DS::heap<int> heap;
  heap.insert(10);
  ASSERT_EQ(heap.size(), 1);
  heap.insert(20);
  ASSERT_EQ(heap.size(), 2);
}

TEST_F(MaxHeapTestFixture, CheckIsEmptyAfterInsertion) {
  MY_DS::heap<int> heap;
  ASSERT_TRUE(heap.is_empty());
  heap.insert(10);
  ASSERT_FALSE(heap.is_empty());
}

TEST_F(MaxHeapTestFixture, CheckSizeAfterMultipleInsertions) {
  MY_DS::heap<int> heap;
  ASSERT_EQ(heap.size(), 0);

  for (int i = 0; i < 10; ++i) {
    heap.insert(i);
    EXPECT_EQ(heap.size(), i + 1);
  }

  ASSERT_EQ(heap.size(), 10);
}

TEST_F(MaxHeapTestFixture, CheckPeekFunctionality) {
  MY_DS::heap<int> heap;
  heap.insert(10);
  ASSERT_EQ(heap.peek(), 10);

  heap.insert(20);
  ASSERT_EQ(heap.peek(), 20);

  heap.insert(15);
  ASSERT_EQ(heap.peek(), 20);
}
