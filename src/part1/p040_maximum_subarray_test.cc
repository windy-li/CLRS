#include "p040_maximum_subarray.h"

std::vector<int> GetSampleVector() {
  return std::vector<int>{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
}

void TestBruteForceMaximumSubarray() {
  std::vector<int> a = GetSampleVector();
  Solution s;
  auto [start, end, max] = s.BruteForceMaximumSubarray(a);
  std::cout << start << " " << end << " " << max << std::endl;
}

void TestDivideAndConquerMaximumSubarray() {
  std::vector<int> a = GetSampleVector();
  int n = a.size();
  Solution s;
  std::vector<int> result = s.DivideAndConquerMaximumSubarray(a, 0, n - 1);
  clrs::PrintVector(result);
}

void TestBottomUpMaximumSubarray() {
  std::vector<int> a = GetSampleVector();
  Solution s;
  std::cout << s.BottomUpMaximumSubarray(a) << std::endl;
}

void TestExtendedBottomUpMaximumSubarray() {
  std::vector<int> a = GetSampleVector();
  Solution s;
  std::vector<int> result = s.ExtendedBottomUpMaximumSubarray(a);
  clrs::PrintVector(result);
}

int main() {
  TestBruteForceMaximumSubarray();
  TestDivideAndConquerMaximumSubarray();
  TestBottomUpMaximumSubarray();
  TestExtendedBottomUpMaximumSubarray();
}
