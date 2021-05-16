#include "clrs.h"

class Solution {
 public:
  int Recursive(const std::vector<int>& p, int n) {
    if (n == 0) {
      return 0;
    }
    int max = std::numeric_limits<int>::min();
    for (int i = 1; i <= n; ++i) {
      max = std::max(max, p[i - 1] + Recursive(p, n - i));
    }
    return max;
  }

  int Memorized(const std::vector<int>& p, int len) {
    int r[len + 1];
    r[0] = 0;
    for (int i = 1; i <= len; ++i) {
      r[i] = std::numeric_limits<int>::min();
    }
    return MemorizedAux(p, len, r);
  }

  int BottomUp(const std::vector<int>& p, int len) {
    int r[len + 1];
    r[0] = 0;
    for (int j = 1; j <= len; ++j) {
      int max = std::numeric_limits<int>::min();
      for (int i = 1; i <= j; ++i) {
        max = std::max(max, p[i - 1] + r[j - i]);
      }
      r[j] = max;
    }
    return r[len];
  }

  void ExtendedBottomUp(const std::vector<int>& p, int len, int& result, std::vector<int>& s) {
    int r[len + 1];
    r[0] = 0;
    for (int j = 1; j <= len; ++j) {
      int max = std::numeric_limits<int>::min();
      for (int i = 1; i <= j; ++i) {
        if (max < p[i - 1] + r[j - i]) {
          max = p[i - 1] + r[j - i];
          s[j] = i;
        }
      }
      r[j] = max;
    }
    result = r[len];
  }

  void ConstructSolution(const std::vector<int>& s, int n) {
    while (n > 0) {
      std::cout << s[n] << " " << std::endl;
      n -= s[n];
    }
  }

 private:
  int MemorizedAux(const std::vector<int>& p, int len, int* r) {
    if (r[len] >= 0) {
      return r[len];
    }
    int max = std::numeric_limits<int>::min();
    for (int i = 1; i <= len; i++) {
      max = std::max(max, p[i - 1] + MemorizedAux(p, len - i, r));
    }
    r[len] = max;
    return max;
  }
};

Solution solution;

void TestRecursive() {
  std::vector<int> p = {1, 5, 8, 9, 10, 17, 17};
  int n = p.size();
  std::cout << solution.Recursive(p, n) << std::endl;
}

void TestMemorized() {
  std::vector<int> p = {1, 5, 8, 9, 10, 17, 17};
  int n = p.size();
  std::cout << solution.Memorized(p, n) << std::endl;
}

void TestBottomUp() {
  std::vector<int> p = {1, 5, 8, 9, 10, 17, 17};
  int n = p.size();
  std::cout << solution.BottomUp(p, n) << std::endl;
}

void TestExtendedBottomUp() {
  std::vector<int> p = {1, 5, 8, 9, 10, 17, 17};
  int n = p.size();
  int result = 0;
  std::vector<int> nums(n + 1);
  solution.ExtendedBottomUp(p, n, result, nums);
  std::cout << result << std::endl;
  solution.ConstructSolution(nums, n);
}

int main() {
  TestRecursive();
  TestMemorized();
  TestBottomUp();
  TestExtendedBottomUp();
}
