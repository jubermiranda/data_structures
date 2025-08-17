#include "heap/heap.h"

#include <gtest/gtest.h>

namespace {
struct Tracked {
  static inline int live_count = 0;
  int *data;

  Tracked() : data(new int(0)) { ++live_count; }
  Tracked(int n) : data(new int(n)) { ++live_count; }
  Tracked(const Tracked& other) : data(new int(*(other.data))) { ++live_count; }

  Tracked& operator=(const Tracked& other) {
    if(this != &other){
      delete data;
      --live_count;

      data = new int(*(other.data));
    }
    return *this;
  }

  ~Tracked(){
    delete data;
    --live_count;
  }

  bool operator<(const Tracked& other) const { return *data < *(other.data); }
  bool operator>(const Tracked& other) const { return *data > *(other.data); }
  bool operator==(const Tracked& other) const { return *data == *(other.data); }
};
};

TEST(MaxHeapTest, EmptyConstructor){
  MY_DS::heap<int> heap;
  EXPECT_EQ(heap.size(), 0);
  EXPECT_TRUE(heap.is_empty());
}

TEST(MaxHeapTest, CopyConstructorCreateIndependentHeap){
  MY_DS::heap<int> heap;

  heap.insert(4);
  heap.insert(2);
  heap.insert(0);
  heap.insert(-1);

  MY_DS::heap<int> copy(heap);
  ASSERT_EQ(heap.size(), copy.size());
  ASSERT_EQ(heap.peek(), copy.peek());

  heap.insert(945);
  ASSERT_NE(heap.peek(), copy.peek());
  ASSERT_TRUE(heap.size() > copy.size());
}

TEST(MaxHeapTest, MoveConstructor){
  MY_DS::heap<int> heap;

  heap.insert(4);
  heap.insert(2);
  heap.insert(0);
  heap.insert(-1);

  MY_DS::heap<int> move(std::move(heap));
  EXPECT_TRUE(heap.is_empty());

  ASSERT_EQ(move.size(), 4);
  ASSERT_EQ(move.peek(), 4);
}

TEST(MaxHeapTest, AssigmentOperator){
  MY_DS::heap<int> heap;

  heap.insert(4);
  heap.insert(2);
  heap.insert(0);
  heap.insert(-1);

  MY_DS::heap<int> other;
  other.insert(55);


  other = heap;
  ASSERT_EQ(other.size(), heap.size());
  ASSERT_EQ(other.peek(), heap.peek());

  heap.insert(132);
  ASSERT_NE(other.peek(), heap.peek());
}

using HeapTracked = MY_DS::heap<Tracked>;
TEST(MaxHeapTest, AssigmentOperatorCleansOldData){
  HeapTracked heap;

  heap.insert(4);
  heap.insert(2);
  heap.insert(0);
  heap.insert(-1);
  ASSERT_EQ(Tracked::live_count, 4);

  HeapTracked other;
  other.insert(100);
  other.insert(200);
  ASSERT_EQ(Tracked::live_count, 6);

  other = heap;
  EXPECT_EQ(other.size(), heap.size());
  EXPECT_EQ(other.peek(), heap.peek());
  ASSERT_EQ(Tracked::live_count, 4*2);
}
