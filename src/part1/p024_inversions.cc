#include "p024_inversions.h"

int main() {
  vector<int> a = {2, 3, 8, 6, 1};
  int n = 5;
  Solution s;
  cout << s.Inversions(a, 0, n - 1) << " inversion pairs";
  clrs::PrintVector(a);
}
