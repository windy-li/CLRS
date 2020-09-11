#include "p070_permute_by_sorting.h"

int main() {
  int n = 10;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i;
  }
  Solution s;
  s.PermuteBySorting(a);
  clrs::PrintVector(a);
}
