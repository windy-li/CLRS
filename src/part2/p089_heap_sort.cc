#include "p089_heap_sort.h"

int main() {
  std::vector<int> a = {5, 2, 4, 6, 1, 3};
  MaxHeap heap;
  heap.Sort(a);
  clrs::PrintVector(a);
}

/*
 * 1 2 3 4 5 6
 */
