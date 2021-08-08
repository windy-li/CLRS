#include "part2_sorting_and_order_statistics/093_diversity_heap.h"

TEST(DiversityHeapTest, TestDiversityHeap) {
  std::vector<int> keys = {2, 8, 7, 1, 3, 5, 6, 4};
  int n = keys.size();
  DiversityHeap heap(n, 3);
  for (int key : keys) {
    heap.Insert(key);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", heap.ExtractMax());
  }
}
