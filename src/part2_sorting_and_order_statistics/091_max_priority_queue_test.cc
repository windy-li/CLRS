#include "part2_sorting_and_order_statistics/091_max_priority_queue.h"

#include "clrs.h"
#include "gtest/gtest.h"

TEST(MaxPriorityQueueTest, MaxPriorityQueue) {
  std::vector<int> keys = {5, 2, 4, 6, 1, 3};
  int n = keys.size();
  MaxPriorityQueue q(n);
  for (int key : keys) {
    q.Insert(key);
  }
  for (int i = 0; i < n; ++i) {
    std::cout << q.ExtractMax() << " ";
  }
}
