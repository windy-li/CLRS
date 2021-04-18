#include "clrs.h"

class Solution {
 public:
  int BinaryBaseRandom(int a, int b) {
    int n = std::ceil(std::log(2) / std::log(b - a + 1));
    std::vector<int> nums(n);
    while (true) {
      for (int i = 0; i < n; ++i) {
        nums[i] = clrs::RandomInt(0, 2);
      }
      int val = a;
      for (int i = n - 1; i >= 0; --i) {
        val += nums[i] * (int)(std::pow(2, n - 1 - i));
      }
      if (val <= b) {
        return val;
      }
    }
  }
};

void TestBinaryBaseRandom() {
  int a = 4, b = 9;
  Solution s;
  for (int i = 0; i < 20; i++) {
    std::cout << s.BinaryBaseRandom(a, b) << " ";
  }
}

int main() { TestBinaryBaseRandom(); }
