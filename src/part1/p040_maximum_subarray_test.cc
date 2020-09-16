#include "p040_maximum_subarray.h"

std::vector<int> GetArray() {
  return std::vector<int>{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
}

void TestBruteForceMaximumSubarray() {
  std::vector<int> a = GetArray();
  Solution s;
  auto [start, end, max] = s.BruteForceMaximumSubarray(a);
  std::cout << start << " " << end << " " << max << std::endl;
}

void TestDivideAndConquerMaximumSubarray() {
  std::vector<int> a = GetArray();
  int n = a.size();
  Solution s;
  clrs::PrintVector(s.DivideAndConquerMaximumSubarray(a, 0, n - 1));
}

void TestBottomUpMaximumSubarray() {
  std::vector<int> a = GetArray();
  Solution s;
  std::cout << s.BottomUpMaximumSubarray(a) << std::endl;
}

void TestExtendedBottomUpMaximumSubarray() {
  std::vector<int> a = GetArray();
  Solution s;
  clrs::PrintVector(s.ExtendedBottomUpMaximumSubarray(a));
}

int main() {
  TestBruteForceMaximumSubarray();
  TestDivideAndConquerMaximumSubarray();
  TestBottomUpMaximumSubarray();
  TestExtendedBottomUpMaximumSubarray();
}
