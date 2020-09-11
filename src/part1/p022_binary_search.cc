#include "p022_binary_search.h"

void TestBinarySearch() {
  std::vector<int> a = {1, 2, 3, 4, 5, 6};
  int k1 = 2;
  int k2 = 7;
  Solution s;
  std::cout << s.BinarySearch(a, k1) << std::endl;
  std::cout << s.BinarySearch(a, k2) << std::endl;
}

void TestRecursiveBinarySearch() {
  std::vector<int> a = {1, 2, 3, 4, 5, 6};
  int n = a.size();
  int k1 = 2;
  int k2 = 7;
  Solution s;
  std::cout << s.RecursiveBinarySearch(a, k1, 0, n - 1) << std::endl;
  std::cout << s.RecursiveBinarySearch(a, k2, 0, n - 1) << std::endl;
}

int main() {
  TestBinarySearch();
  TestRecursiveBinarySearch();
}
