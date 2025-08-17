#include "heap/heap.h"

#include <gtest/gtest.h>
#include <random>
#include <vector>

class MaxHeapIntTestFixture : public ::testing::Test {
protected:
  MY_DS::heap<int> heap;
  void SetUp() override {
  }

  void TearDown() override {
  }
};

int gen_rand_int(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(min, max);
  return dis(gen);
}


TEST_F(MaxHeapIntTestFixture, CheckStatusAfterCreation) {
  ASSERT_EQ(heap.size(), 0);
  ASSERT_TRUE(heap.is_empty());
}

TEST_F(MaxHeapIntTestFixture, CheckSizeAfterInsertion) {
  heap.insert(10);
  ASSERT_EQ(heap.size(), 1);
  heap.insert(20);
  ASSERT_EQ(heap.size(), 2);
}

TEST_F(MaxHeapIntTestFixture, CheckStatusAfterClear){
  heap.insert(10);
  heap.insert(20);
  heap.insert(40);
  ASSERT_EQ(heap.size(), 3);

  heap.clear();

  ASSERT_EQ(heap.size(), 0);
  ASSERT_TRUE(heap.is_empty());
}

TEST_F(MaxHeapIntTestFixture, CheckIsEmptyAfterInsertion) {
  ASSERT_TRUE(heap.is_empty());
  heap.insert(10);
  ASSERT_FALSE(heap.is_empty());
}

TEST_F(MaxHeapIntTestFixture, CheckSizeAfterMultipleInsertions) {
  ASSERT_EQ(heap.size(), 0);

  for (int i = 0; i < 10; ++i) {
    heap.insert(i);
    EXPECT_EQ(heap.size(), i + 1);
  }

  ASSERT_EQ(heap.size(), 10);
}

TEST_F(MaxHeapIntTestFixture, CheckPeekFunctionality) {
  heap.insert(10);
  ASSERT_EQ(heap.peek(), 10);

  heap.insert(20);
  ASSERT_EQ(heap.peek(), 20);

  heap.insert(15);
  ASSERT_EQ(heap.peek(), 20);
}

TEST_F(MaxHeapIntTestFixture, LargeInsertions){
  std::vector<int> large_data;
  for(int i = 0; i < 4000; i++) {
    large_data.push_back(gen_rand_int(0, 20000));
    heap.insert(large_data.back());
    
    ASSERT_EQ(heap.size(), i + 1);
    int expected_max = *std::max_element(large_data.begin(), large_data.end());
    ASSERT_EQ(heap.peek(), expected_max);
  }
}

TEST_F(MaxHeapIntTestFixture, CheckExtractFunctionality) {
  ASSERT_TRUE(heap.is_empty());
  ASSERT_THROW(heap.extract(), std::runtime_error);

  heap.insert(10);
  heap.extract();
  ASSERT_TRUE(heap.is_empty());

  heap.insert(20);
  heap.insert(40);
  heap.insert(30);
  ASSERT_EQ(heap.size(), 3);

  int extracted_item = heap.extract();
  ASSERT_EQ(extracted_item, 40);
  ASSERT_EQ(heap.size(), 2);

  extracted_item = heap.extract();
  ASSERT_EQ(extracted_item, 30);
  ASSERT_EQ(heap.size(), 1);

  extracted_item = heap.extract();
  ASSERT_EQ(extracted_item, 20);
  ASSERT_EQ(heap.size(), 0);

  ASSERT_TRUE(heap.is_empty());
}
