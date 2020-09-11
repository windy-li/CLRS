#include "p023_bubble_sort.h"

void TestBubbleSort() {
  vector<int> a = {1, 3, 4, 2};
  Solution s;
  s.BubbleSort(a);
  clrs::PrintVector(a);
}

int main() { TestBubbleSort(); }
