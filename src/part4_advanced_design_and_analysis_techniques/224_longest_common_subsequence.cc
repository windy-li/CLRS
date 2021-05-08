#include "clrs.h"

const int kLeft = 0;
const int kTop = 1;
const int kTurn = 2;

class Solution {
 public:
  int Recursive(std::vector<char>& x, std::vector<char>& y, int m, int n) {
    if (m == 0 || n == 0) {
      return 0;
    } else if (x[m - 1] == y[n - 1]) {
      return Recursive(x, y, m - 1, n - 1) + 1;
    } else {
      return std::max(Recursive(x, y, m - 1, n), Recursive(x, y, m, n - 1));
    }
  }

  int Memorized(std::vector<char>& x, std::vector<char>& y) {
    int m = x.size();
    int n = y.size();
    std::vector<std::vector<int>> c(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (i == 0 || j == 0) {
          c[i][j] = 0;
        } else {
          c[i][j] = std::numeric_limits<int>::min();
        }
      }
    }
    return MemorizedAux(x, y, c, m, n);
  }

  int BottomUp(std::vector<char>& x, std::vector<char>& y) {
    int m = x.size();
    int n = y.size();
    std::vector<std::vector<int>> c(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= m; ++i) {
      c[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j) {
      c[0][j] = 0;
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (x[i - 1] == y[j - 1]) {
          c[i][j] = c[i - 1][j - 1] + 1;
        } else {
          c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
        }
      }
    }
    return c[m][n];
  }

  std::tuple<int, std::vector<std::vector<int>>> ExtendedBottomUp(std::vector<char>& x, std::vector<char>& y) {
    int m = x.size();
    int n = y.size();
    std::vector<std::vector<int>> c(m + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> b(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= m; ++i) {
      c[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j) {
      c[0][j] = 0;
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (x[i - 1] == y[j - 1]) {
          c[i][j] = c[i - 1][j - 1] + 1;
          b[i][j] = kTurn;
        } else {
          if (c[i - 1][j] >= c[i][j - 1]) {
            c[i][j] = c[i - 1][j];
            b[i][j] = kTop;
          } else {
            c[i][j] = c[i][j - 1];
            b[i][j] = kLeft;
          }
        }
      }
    }
    return {c[m][n], b};
  }

  void ConstructSolution(std::vector<std::vector<int>>& b, std::vector<char>& x, int i, int j) {
    if (i == 0 || j == 0) {
      return;
    }
    if (b[i][j] == kTurn) {
      ConstructSolution(b, x, i - 1, j - 1);
      std::cout << x[i - 1];
    } else {
      if (b[i][j] == kTop) {
        ConstructSolution(b, x, i - 1, j);
      } else {
        ConstructSolution(b, x, i, j - 1);
      }
    }
  }

 private:
  int MemorizedAux(std::vector<char>& x, std::vector<char>& y, std::vector<std::vector<int>>& c, int i, int j) {
    if (c[i][j] >= 0) {
      return c[i][j];
    }
    if (x[i - 1] == y[j - 1]) {
      c[i][j] = MemorizedAux(x, y, c, i - 1, j - 1) + 1;
    } else {
      c[i][j] = std::max(MemorizedAux(x, y, c, i - 1, j), MemorizedAux(x, y, c, i, j - 1));
    }
    return c[i][j];
  }
};

Solution s;

void TestRecursive() {
  std::vector<char> x = {'A', 'B', 'C', 'B', 'D', 'B', 'A'};
  std::vector<char> y = {'B', 'D', 'C', 'A', 'B', 'A'};
  int m = x.size();
  int n = y.size();
  std::cout << s.Recursive(x, y, m, n) << std::endl;
}

void TestMemorized() {
  std::vector<char> x = {'A', 'B', 'C', 'B', 'D', 'B', 'A'};
  std::vector<char> y = {'B', 'D', 'C', 'A', 'B', 'A'};
  std::cout << s.Memorized(x, y) << std::endl;
}

void TestBottomUp() {
  std::vector<char> x = {'A', 'B', 'C', 'B', 'D', 'B', 'A'};
  std::vector<char> y = {'B', 'D', 'C', 'A', 'B', 'A'};
  std::cout << s.BottomUp(x, y) << std::endl;
}

void TestExtendedBottomUp() {
  std::vector<char> x = {'A', 'B', 'C', 'B', 'D', 'B', 'A'};
  std::vector<char> y = {'B', 'D', 'C', 'A', 'B', 'A'};
  int m = x.size();
  int n = y.size();
  auto [a, b] = s.ExtendedBottomUp(x, y);
  std::cout << a << std::endl;
  s.ConstructSolution(b, x, m, n);
}

int main() {
  TestRecursive();
  TestMemorized();
  TestBottomUp();
  TestExtendedBottomUp();
}
