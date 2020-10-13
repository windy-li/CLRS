#include "clrs.h"

class Solution {
 public:
  static int Recursive(int n) {
    if (n == 1 || n == 2) {
      return 1;
    }
    return Recursive(n - 2) + Recursive(n - 1);
  }

  static int TailRecursive(int n, int a, int b) {
    if (n == 1) {
      return a;
    }
    return TailRecursive(n - 1, b, a + b);
  }

  static int Memorized(int n) {
    int d[n + 1];
    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= n; ++i) {
      d[i] = INT_MIN;
    }
    return MemorizedAux(n, d);
  }

  static void BottomUp(int n, int *d) {
    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= n; ++i) {
      d[i] = d[i - 1] + d[i - 2];
    }
  }

 private:
  static int MemorizedAux(int i, int *d) {
    if (d[i] >= 0) {
      return d[i];
    }
    d[i] = MemorizedAux(i - 1, d) + MemorizedAux(i - 2, d);
    return d[i];
  }
};

int main() {
  int n = 7;
  std::cout << Solution::Recursive(n) << std::endl;
  std::cout << Solution::TailRecursive(n, 1, 1) << std::endl;
  std::cout << Solution::Memorized(n) << std::endl;
  int d[n + 1];
  Solution::BottomUp(n, d);
  for (int i = 1; i <= n; ++i) {
    std::cout << d[i] << " " << std::endl;
  }
  return 0;
}
