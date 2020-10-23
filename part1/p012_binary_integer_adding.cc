#include "clrs.h"

class Solution {
 public:
  std::vector<int> BinaryIntegerAdding(std::vector<int>& nums_a, std::vector<int>& nums_b) {
    int n = nums_a.size();
    std::vector<int> nums_c(n + 1);
    int bit = 0;
    for (int i = n - 1; i >= 0; --i) {
      int y = nums_a[i] + nums_b[i] + bit;
      nums_c[i + 1] = y % 2;
      if (y >= 2) {
        bit = 1;
      } else {
        bit = 0;
      }
    }
    nums_c[0] = bit;
    return nums_c;
  }
};

void TestBinaryIntegerAdding() {
  std::vector<int> num_a = {1, 0, 1, 1, 1, 0};
  std::vector<int> num_b = {0, 1, 1, 1, 0, 0};
  Solution s;
  std::vector<int> nums_c = s.BinaryIntegerAdding(num_a, num_b);
  clrs::PrintVector(nums_c);
}

int main() { TestBinaryIntegerAdding(); }
