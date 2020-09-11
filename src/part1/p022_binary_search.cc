#include "p022_binary_search.h"

void TestBinarySearch() {
  vector<int> a = {1, 2, 3, 4, 5, 6};
  int k1 = 2;
  int k2 = 7;
  Solution s;
  cout << s.BinarySearch(a, k1) << endl;
  cout << s.BinarySearch(a, k2) << endl;
}

void TestRecursiveBinarySearch() {
  vector<int> a = {1, 2, 3, 4, 5, 6};
  int n = a.size();
  int k1 = 2;
  int k2 = 7;
  Solution s;
  cout << s.RecursiveBinarySearch(a, k1, 0, n - 1) << endl;
  cout << s.RecursiveBinarySearch(a, k2, 0, n - 1) << endl;
}

int main() {
  TestBinarySearch();
  TestRecursiveBinarySearch();
}
