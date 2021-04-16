#include "clrs.h"

class Solution {
 public:
  int Recursive(int n) {
    if (n == 1 || n == 2) {
      return 1;
    }
    return Recursive(n - 2) + Recursive(n - 1);
  }

  int TailRecursive(int n, int a, int b) {
    if (n == 1) {
      return a;
    }
    return TailRecursive(n - 1, b, a + b);
  }

  int Memorized(int n) {
    std::vector<int> d(n + 1);
    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= n; ++i) {
      d[i] = std::numeric_limits<int>::min();
    }
    return MemorizedAux(n, d);
  }

  void BottomUp(int n, std::vector<int>& d) {
    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= n; ++i) {
      d[i] = d[i - 1] + d[i - 2];
    }
  }

 private:
  int MemorizedAux(int i, std::vector<int>& d) {
    if (d[i] >= 0) {
      return d[i];
    }
    d[i] = MemorizedAux(i - 1, d) + MemorizedAux(i - 2, d);
    return d[i];
  }
};

const int n = 7;
Solution s;

void TestRecursive() { std::cout << s.Recursive(n) << std::endl; }

void TestTailRecursive() { std::cout << s.TailRecursive(n, 1, 1) << std::endl; }

void TestMemorized() { std::cout << s.Memorized(n) << std::endl; }

void TestBottomUp() {
  std::vector<int> d(n + 1);
  s.BottomUp(n, d);
  for (int i = 1; i <= n; ++i) {
    std::cout << d[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  TestRecursive();
  TestTailRecursive();
  TestMemorized();
  TestBottomUp();
}
