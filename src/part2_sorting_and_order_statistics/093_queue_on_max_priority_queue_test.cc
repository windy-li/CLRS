#include "part2_sorting_and_order_statistics/093_queue_on_max_priority_queue.h"

#include "gtest/gtest.h"

TEST(QueueOnMaxPriorityQueueTest, TestQueue) {
  auto keys = std::vector<int>{5, 2, 4, 6, 1, 3};
  int n = keys.size();
  auto q = Queue(n);
  for (int i = 0; i < n; ++i) {
    q.Push(keys[i]);
  }
  for (int i = 0; i < n; ++i) {
    Node* node = q.Pop();
    printf("{ key: %d, priority: %d }\n", node->key, node->priority);
  }
}

/*
 * {key: 5, priority: 5}
 * {key: 2, priority: 4}
 * {key: 4, priority: 3}
 * {key: 6, priority: 2}
 * {key: 1, priority: 1}
 * {key: 3, priority: 0}
 */
