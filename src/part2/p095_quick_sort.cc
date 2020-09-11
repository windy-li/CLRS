#include "p095_quick_sort.h"

void TestQuickSort() {
  std::vector<int> a = {1, 6, 2, 8};
  int n = a.size();
  Solution s;
  s.QuickSort(a, 0, n - 1);
  clrs::PrintVector(a);
}

void TestIterativeQuickSort() {
  std::vector<int> a = {1, 6, 2, 8};
  int n = a.size();
  Solution s;
  s.IterativeQuickSort(a, 0, n - 1);
  clrs::PrintVector(a);
}

int main() {
  TestQuickSort();
  TestIterativeQuickSort();
}
