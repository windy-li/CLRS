#include "clrs.h"

class Solution {
 public:
  std::vector<int> BinaryIntegerAdding(const std::vector<int>& a, const std::vector<int>& b) {
    int n = a.size();
    std::vector<int> c(n + 1);
    int bit = 0;
    for (int i = n - 1; i >= 0; --i) {
      int y = a[i] + b[i] + bit;
      c[i + 1] = y % 2;
      if (y >= 2) {
        bit = 1;
      } else {
        bit = 0;
      }
    }
    c[0] = bit;
    return c;
  }
};

Solution solution;

void TestBinaryIntegerAdding() {
  std::vector<int> a = {1, 0, 1, 1, 1, 0};
  std::vector<int> b = {0, 1, 1, 1, 0, 0};
  std::vector<int> c = solution.BinaryIntegerAdding(a, b);
  clrs::PrintVector(c);
}

int main() { TestBinaryIntegerAdding(); }
