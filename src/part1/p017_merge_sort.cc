#include "p017_merge_sort.h"

void TestMergeSort() {
  std::vector<int> a = {1, 3, 4, 2};
  int n = a.size();
  Solution s;
  s.MergeSort(a, 0, n - 1);
  clrs::PrintVector(a);
}

void TestMergeSortBySentinels() {
  std::vector<int> a = {1, 3, 4, 2};
  int n = a.size();
  Solution s;
  s.MergeSortBySentinels(a, 0, n - 1);
  clrs::PrintVector(a);
}

int main() {
  TestMergeSort();
  TestMergeSortBySentinels();
}
