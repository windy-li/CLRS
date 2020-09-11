#include "p040_maximum_subarray.h"

vector<int> GetArray() {
  return vector<int>{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
}

void TestBruteForceMaximumSubarray() {
  vector<int> a = GetArray();
  Solution s;
  auto [start, end, max] = s.BruteForceMaximumSubarray(a);
  cout << start << " " << end << " " << max << endl;
}

void TestDivideAndConquerMaximumSubarray() {
  vector<int> a = GetArray();
  int n = a.size();
  Solution s;
  clrs::PrintVector(s.DivideAndConquerMaximumSubarray(a, 0, n - 1));
}

void TestBottomUpMaximumSubarray() {
  vector<int> a = GetArray();
  Solution s;
  cout << s.BottomUpMaximumSubarray(a) << endl;
}

void TestExtendedBottomUpMaximumSubarray() {
  vector<int> a = GetArray();
  Solution s;
  clrs::PrintVector(s.ExtendedBottomUpMaximumSubarray(a));
}

int main() {
  TestBruteForceMaximumSubarray();
  TestDivideAndConquerMaximumSubarray();
  TestBottomUpMaximumSubarray();
  TestExtendedBottomUpMaximumSubarray();
}
