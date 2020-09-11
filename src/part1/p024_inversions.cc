#include "p024_inversions.h"

int main() {
  std::vector<int> a = {2, 3, 8, 6, 1};
  int n = 5;
  Solution s;
  std::cout << s.Inversions(a, 0, n - 1) << " inversion pairs";
  clrs::PrintVector(a);
}
