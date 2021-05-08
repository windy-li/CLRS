#include "clrs.h"

class Solution {
 public:
  std::vector<std::vector<int>> MatrixMultiply(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b) {
    int a_row = a.size();
    int a_col = a[0].size();
    int b_row = b.size();
    int b_col = b[0].size();
    std::vector<std::vector<int>> c(a_row, std::vector<int>(b_col));
    if (a_col != b_row) {
      throw std::invalid_argument("incompatible dimensions");
    }
    for (int i = 0; i < a_row; ++i) {
      for (int j = 0; j < b_col; ++j) {
        c[i][j] = 0;
        for (int k = 0; k < a_col; ++k) {
          c[i][j] += a[i][k] + b[k][j];
        }
      }
    }
    return c;
  }

  int Recursive(std::vector<int>& p, int i, int j) {
    if (i == j) {
      return 0;
    }
    int min = std::numeric_limits<int>::max();
    for (int k = i; k < j; ++k) {
      min = std::min(min, Recursive(p, i, k) + Recursive(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return min;
  }

  int Memorized(std::vector<int>& p) {
    int n = p.size() - 1;
    std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        if (i == j) {
          m[i][j] = 0;
        } else {
          m[i][j] = std::numeric_limits<int>::max();
        }
      }
    }
    return MemorizedAux(p, m, 1, n);
  }

  int BottomUp(std::vector<int>& p) {
    int n = p.size() - 1;
    int m[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) {
      m[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        int min = std::numeric_limits<int>::max();
        for (int k = i; k < j; ++k) {
          min = std::min(min, m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
        }
        m[i][j] = min;
      }
    }
    return m[1][n];
  }

  std::tuple<int, std::vector<std::vector<int>>> ExtendedBottomUp(std::vector<int>& p) {
    int n = p.size() - 1;
    std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> s(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
      m[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        int min = std::numeric_limits<int>::max();
        for (int k = i; k < j; ++k) {
          if (min > m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]) {
            min = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
            s[i][j] = k;
          }
        }
        m[i][j] = min;
      }
    }
    return {m[1][n], s};
  }

  void ConstructSolution(std::vector<std::vector<int>>& s, int i, int j) {
    if (i == j) {
      std::cout << "A" << i;
    } else {
      std::cout << "(";
      ConstructSolution(s, i, s[i][j]);
      ConstructSolution(s, s[i][j] + 1, j);
      std::cout << ")";
    }
  }

 private:
  int MemorizedAux(std::vector<int>& p, std::vector<std::vector<int>>& m, int i, int j) {
    if (m[i][j] < std::numeric_limits<int>::max()) {
      return m[i][j];
    }
    int min = std::numeric_limits<int>::max();
    for (int k = i; k < j; ++k) {
      min = std::min(min, MemorizedAux(p, m, i, k) + MemorizedAux(p, m, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    m[i][j] = min;
    return min;
  }
};

void TestMatrixMultiply() {
  Solution s;
  std::vector<std::vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}};
  std::vector<std::vector<int>> b = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  std::vector<std::vector<int>> c = s.MatrixMultiply(a, b);
  int a_row = a.size();
  int b_col = b[0].size();
  for (int i = 0; i < a_row; ++i) {
    for (int j = 0; j < b_col; ++j) {
      std::cout << c[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void TestRecursive() {
  Solution s;
  std::vector<int> p = {30, 35, 15, 5, 10, 20, 25};
  std::cout << s.Recursive(p, 1, p.size() - 1) << std::endl;
}

void TestMemorized() {
  Solution s;
  std::vector<int> p = {30, 35, 15, 5, 10, 20, 25};
  std::cout << s.Memorized(p) << std::endl;
}

void TestBottomUp() {
  Solution s;
  std::vector<int> p = {30, 35, 15, 5, 10, 20, 25};
  std::cout << s.BottomUp(p) << std::endl;
}

void TestExtendedBottomUp() {
  Solution solution;
  std::vector<int> p = {30, 35, 15, 5, 10, 20, 25};
  int n = p.size() - 1;
  auto [m, s] = solution.ExtendedBottomUp(p);
  std::cout << m << std::endl;
  solution.ConstructSolution(s, 1, n);
}

int main() {
  TestMatrixMultiply();
  TestRecursive();
  TestMemorized();
  TestBottomUp();
  TestExtendedBottomUp();
}
