#include "clrs.h"

class Solution {
 public:
  int Recursive(std::vector<int>& p, int n) {
    if (n == 0) {
      return 0;
    }
    int max = INT_MIN;
    for (int i = 1; i <= n; ++i) {
      max = std::max(max, p[i - 1] + Recursive(p, n - i));
    }
    return max;
  }

  int Memorized(std::vector<int>& p, int len) {
    int r[len + 1];
    r[0] = 0;
    for (int i = 1; i <= len; ++i) {
      r[i] = INT_MIN;
    }
    return MemorizedAux(p, len, r);
  }

  int BottomUp(std::vector<int>& p, int len) {
    int r[len + 1];
    r[0] = 0;
    for (int j = 1; j <= len; ++j) {
      int max = INT_MIN;
      for (int i = 1; i <= j; ++i) {
        max = std::max(max, p[i - 1] + r[j - i]);
      }
      r[j] = max;
    }
    return r[len];
  }

  void ExtendedBottomUp(std::vector<int>& p, int len, int& result, std::vector<int>& s) {
    int r[len + 1];
    r[0] = 0;
    for (int j = 1; j <= len; ++j) {
      int max = INT_MIN;
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

  void ConstructSolution(std::vector<int>& s, int n) {
    while (n > 0) {
      std::cout << s[n] << " " << std::endl;
      n -= s[n];
    }
  }

 private:
  int MemorizedAux(std::vector<int>& p, int len, int* r) {
    if (r[len] >= 0) {
      return r[len];
    }
    int max = INT_MIN;
    for (int i = 1; i <= len; i++) {
      max = std::max(max, p[i - 1] + MemorizedAux(p, len - i, r));
    }
    r[len] = max;
    return max;
  }
};

int main() {
  std::vector<int> p = {1, 5, 8, 9, 10, 17, 17};
  int n = p.size();
  Solution solution;
  std::cout << solution.Recursive(p, n) << std::endl;
  std::cout << solution.Memorized(p, n) << std::endl;
  std::cout << solution.BottomUp(p, n) << std::endl;
  int result = 0;
  std::vector<int> s(n + 1);
  solution.ExtendedBottomUp(p, n, result, s);
  std::cout << result << std::endl;
  solution.ConstructSolution(s, n);
}
