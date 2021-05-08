#include "clrs.h"

class Solution {
 public:
  int Recursive(std::vector<int>& s, std::vector<int>& f, int k, int n, int a) {
    int m = k + 1;
    while (m <= n && s[m] < f[k]) {
      m++;
    }
    if (m <= n) {
      a++;
      return Recursive(s, f, m, n, a);
    } else {
      return a;
    }
  }

  int Greedy(std::vector<int>& s, std::vector<int>& f) {
    int n = s.size();
    int i = 0;
    int c = 0;
    for (int j = 1; j < n; ++j) {
      if (s[j] >= f[i]) {
        i = j;
        c++;
      }
    }
    return c;
  }

  void ConstructSolution(std::vector<int>& s, std::vector<int>& f) {
    int n = s.size();
    int i = 1;
    std::cout << i << " ";
    for (int j = 1; j < n; ++j) {
      if (s[j] >= f[i]) {
        std::cout << j << " ";
        i = j;
      }
    }
  }
};

void TestRecursive() {
  Solution solution;
  std::vector<int> s = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  std::vector<int> f = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
  int n = s.size() - 1;
  std::cout << solution.Recursive(s, f, 0, n, 0) << std::endl;
}

void TestGreedy() {
  Solution solution;
  std::vector<int> s = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  std::vector<int> f = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
  std::cout << solution.Greedy(s, f) << std::endl;
}

void TestConstructSolution() {
  Solution solution;
  std::vector<int> s = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  std::vector<int> f = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
  solution.ConstructSolution(s, f);
}

int main() {
  TestRecursive();
  TestGreedy();
  TestConstructSolution();
}
