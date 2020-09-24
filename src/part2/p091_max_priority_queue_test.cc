#include "p091_max_priority_queue.h"

int main() {
  std::vector<int> keys = {5, 2, 4, 6, 1, 3};
  int n = keys.size();
  MaxPriorityQueue self(n);
  for (int key : keys) {
    self.Insert(key);
  }
  for (int i = 0; i < n; ++i) {
    std::cout << self.ExtractMax() << " ";
  }
}

/*
 * 6 5 4 3 2 1
 */
