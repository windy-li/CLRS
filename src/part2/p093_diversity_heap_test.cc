#include "p093_diversity_heap.h"

int main() {
  int keys[] = {2, 8, 7, 1, 3, 5, 6, 4};
  int n = 8;
  DiversityHeap heap(n, 3);
  for (int key : keys) {
    heap.Insert(key);
  }
  for (int i = 0; i < n; i++) {
    std::cout << heap.ExtractMax() << " ";
  }
}

/*
 * 8 7 6 5 4 3 2 1
 */
