#include "clrs.h"

class Solution {
 public:
  std::vector<std::vector<int>> MatrixMultiply(std::vector<std::vector<int>>& a,
                                               std::vector<std::vector<int>>& b) {
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

  int Recursive(int* p, int i, int j) {
    if (i == j) {
      return 0;
    }
    int min = INT_MAX;
    for (int k = i; k < j; ++k) {
      min = std::min(min, Recursive(p, i, k) + Recursive(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return min;
  }

  int Memorized(int* p, int len) {
    int n = len - 1;
    int m[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        if (i == j) {
          m[i][j] = 0;
        } else {
          m[i][j] = INT_MAX;
        }
      }
    }
    return MemorizedAux(p, (int*)m, n + 1, 1, n);
  }

  int BottomUp(int* p, int length) {
    int n = length - 1;
    int m[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) {
      m[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        int min = INT_MAX;
        for (int k = i; k < j; ++k) {
          min = std::min(min, m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
        }
        m[i][j] = min;
      }
    }
    return m[1][n];
  }

  void ExtendedBottomUp(int* p, int length, int& result, int* s, int sCol) {
    int n = length - 1;
    int m[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) {
      m[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        int min = INT_MAX;
        for (int k = i; k < j; ++k) {
          if (min > m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]) {
            min = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
            *((s + i * sCol) + j) = k;
          }
        }
        m[i][j] = min;
      }
    }
    result = m[1][n];
  }

  void ConstructSolution(int* s, int s_col, int i, int j) {
    if (i == j) {
      std::cout << "A" << i;
    } else {
      std::cout << "(";
      ConstructSolution(s, s_col, i, *((s + i * s_col) + j));
      ConstructSolution(s, s_col, *((s + i * s_col) + j) + 1, j);
      std::cout << ")";
    }
  }

 private:
  int MemorizedAux(int* p, int* m, int mCol, int i, int j) {
    if (*((m + i * mCol) + j) < INT_MAX) {
      return *((m + i * mCol) + j);
    }
    int min = INT_MAX;
    for (int k = i; k < j; ++k) {
      min = std::min(min, MemorizedAux(p, m, mCol, i, k) + MemorizedAux(p, m, mCol, k + 1, j) +
                              p[i - 1] * p[k] * p[j]);
    }
    *((m + i * mCol) + j) = min;
    return min;
  }
};

void TestMatrixMultiply() {
  std::vector<std::vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}};
  std::vector<std::vector<int>> b = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  int a_row = a.size();
  int b_col = b[0].size();
  Solution s;
  std::vector<std::vector<int>> c = s.MatrixMultiply(a, b);
  for (int i = 0; i < a_row; ++i) {
    for (int j = 0; j < b_col; ++j) {
      std::cout << c[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() { TestMatrixMultiply(); }
