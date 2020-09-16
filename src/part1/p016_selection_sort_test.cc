#include "p016_selection_sort.h"

void TestSelectionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  Solution s;
  s.SelectionSort(nums);
  clrs::PrintVector(nums);
}

int main() { TestSelectionSort(); }
