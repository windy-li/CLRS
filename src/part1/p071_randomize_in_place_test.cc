#include "p071_randomize_in_place.h"

void TestRandomizeInPlace() {
  int n = 10;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i;
  }
  Solution s;
  s.RandomizeInPlace(a);
  clrs::PrintVector(a);
}

int main() { TestRandomizeInPlace(); }
