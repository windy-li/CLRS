#include "p010_insertion_sort.h"

void TestInsertionSort() {
  vector<int> nums = {1, 3, 4, 2};
  Solution s;
  s.InsertionSort(nums);
  clrs::PrintVector(nums);
}

void TestRecursiveInsertionSort() {
  vector<int> nums = {1, 3, 4, 2};
  int n = nums.size();
  Solution s;
  s.RecursiveInsertionSort(nums, n - 1);
  clrs::PrintVector(nums);
}

void TestNonIncreasingInsertionSort() {
  vector<int> nums = {1, 3, 4, 2};
  Solution s;
  s.NonIncreasingInsertionSort(nums);
  clrs::PrintVector(nums);
}

void TestBinaryInsertionSort() {
  vector<int> nums = {1, 3, 4, 2};
  Solution s;
  s.BinaryInsertionSort(nums);
  clrs::PrintVector(nums);
}

int main() {
  TestInsertionSort();
  TestRecursiveInsertionSort();
  TestNonIncreasingInsertionSort();
  TestBinaryInsertionSort();
}
