#include "clrs.h"

class Solution {
 public:
  double Recursive(std::vector<double>& p, std::vector<double>& q, int i, int j) {
    if (j == i - 1) {
      return q[i - 1];
    }
    double min = std::numeric_limits<double>::max();
    double s = Sum(p, q, i, j);
    for (int k = i; k <= j; ++k) {
      min = std::min(min, Recursive(p, q, i, k - 1) + Recursive(p, q, k + 1, j) + s);
    }
    return min;
  }

  double Memorized(std::vector<double>& p, std::vector<double>& q) {
    int n = p.size() - 1;
    std::vector<std::vector<double>> e(n + 2, std::vector<double>(n + 2));
    for (int i = 1; i <= n + 1; i++) {
      for (int j = i - 1; j <= n + 1; j++) {
        if (j == i - 1) {
          e[i][j] = q[i - 1];
        } else {
          e[i][j] = std::numeric_limits<double>::max();
        }
      }
    }
    return MemorizedAux(p, q, e, 1, n);
  }

  double BottomUp(std::vector<double>& p, std::vector<double>& q) {
    int n = p.size() - 1;
    std::vector<std::vector<double>> e(n + 2, std::vector<double>(n + 2));
    std::vector<std::vector<double>> w(n + 2, std::vector<double>(n + 2));
    for (int i = 1; i <= n + 1; ++i) {
      e[i][i - 1] = q[i - 1];
      w[i][i - 1] = q[i - 1];
    }
    for (int len = 1; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        double min = std::numeric_limits<double>::max();
        w[i][j] = w[i][j - 1] + p[j] + q[j];
        for (int k = i; k <= j; ++k) {
          min = std::min(min, e[i][k - 1] + e[k + 1][j] + w[i][j]);
        }
        e[i][j] = min;
      }
    }
    return e[1][n];
  }

  std::tuple<double, std::vector<std::vector<int>>> ExtendedBottomUp(std::vector<double>& p, std::vector<double>& q) {
    int n = p.size() - 1;
    std::vector<std::vector<double>> e(n + 2, std::vector<double>(n + 2));
    std::vector<std::vector<double>> w(n + 2, std::vector<double>(n + 2));
    std::vector<std::vector<int>> root(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n + 1; ++i) {
      e[i][i - 1] = q[i - 1];
      w[i][i - 1] = q[i - 1];
    }
    for (int len = 1; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        w[i][j] = w[i][j - 1] + p[j] + q[j];
        double min = std::numeric_limits<double>::max();
        for (int k = i; k <= j; ++k) {
          if (min > e[i][k - 1] + e[k + 1][j] + w[i][j]) {
            min = e[i][k - 1] + e[k + 1][j] + w[i][j];
            root[i][j] = k;
          }
        }
        e[i][j] = min;
      }
    }
    return {e[1][n], root};
  }

  std::tuple<int, std::vector<std::vector<int>>> OptimalBinarySearchTree(std::vector<double>& p, std::vector<double>& q,
                                                                         int n) {
    std::vector<std::vector<double>> e(n + 2, std::vector<double>(n + 1));
    std::vector<std::vector<double>> w(n + 2, std::vector<double>(n + 1));
    std::vector<std::vector<int>> root(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n + 1; ++i) {
      e[i][i - 1] = q[i - 1];
      w[i][i - 1] = q[i - 1];
    }
    for (int len = 1; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        double min = std::numeric_limits<double>::max();
        w[i][j] = w[i][j - 1] + p[j] + q[j];
        for (int k = i; k <= j; ++k) {
          if (min > e[i][k - 1] + e[k + 1][j] + w[i][j]) {
            min = e[i][k - 1] + e[k + 1][j] + w[i][j];
            root[i][j] = k;
          }
        }
        e[i][j] = min;
      }
    }
    return {e[1][n], root};
  }

 private:
  double Sum(std::vector<double>& p, std::vector<double>& q, int i, int j) {
    double s = 0;
    s += q[i - 1];
    for (int k = i; k <= j; ++k) {
      s += p[k];
      s += q[k];
    }
    return s;
  }

  double MemorizedAux(std::vector<double>& p, std::vector<double>& q, std::vector<std::vector<double>>& e, int i,
                      int j) {
    if (e[i][j] < std::numeric_limits<double>::max()) {
      return e[i][j];
    }
    double min = std::numeric_limits<double>::max();
    double s = Sum(p, q, i, j);
    for (int k = i; k <= j; k++) {
      min = std::min(min, MemorizedAux(p, q, e, i, k - 1) + MemorizedAux(p, q, e, k + 1, j) + s);
    }
    e[i][j] = min;
    return min;
  }
};

void TestRecursive() {
  Solution s;
  std::vector<double> p = {0.00, 0.15, 0.10, 0.05, 0.10, 0.20};
  std::vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
  int n = p.size() - 1;
  std::cout << s.Recursive(p, q, 1, n) << std::endl;
}

void TestMemorized() {
  Solution s;
  std::vector<double> p = {0.00, 0.15, 0.10, 0.05, 0.10, 0.20};
  std::vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
  std::cout << s.Memorized(p, q) << std::endl;
}

void TestBottomUp() {
  Solution s;
  std::vector<double> p = {0.00, 0.15, 0.10, 0.05, 0.10, 0.20};
  std::vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
  std::cout << s.BottomUp(p, q) << std::endl;
}

void TestExtendedBottomUp() {
  Solution s;
  std::vector<double> p = {0.00, 0.15, 0.10, 0.05, 0.10, 0.20};
  std::vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
  int n = p.size() - 1;
  auto [a, b] = s.ExtendedBottomUp(p, q);
  std::cout << a << std::endl;
  std::cout << b[1][n] << std::endl;
}

int main() {
  TestRecursive();
  TestMemorized();
  TestBottomUp();
  TestExtendedBottomUp();
}
