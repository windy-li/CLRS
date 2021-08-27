#include "clrs.h"

class Solution {
 public:
  int Recursive(std::vector<int>& nums, int p, int r, int i) {
    if (p == r) {
      return nums[p];
    }
    int q = RandomizedPartition(nums, p, r);
    int k = q - p + 1;
    if (i == k) {
      return nums[q];
    } else if (i < k) {
      return Recursive(nums, p, q - 1, i);
    } else {
      return Recursive(nums, q + 1, r, i - k);
    }
  }

  int Iterative(std::vector<int>& nums, int p, int r, int i) {
    while (p < r) {
      int q = RandomizedPartition(nums, p, r);
      int k = q - p + 1;
      if (i == k) {
        return nums[q];
      } else if (i < k) {
        r = q - 1;
      } else {
        p = q + 1;
        i -= k;
      }
    }
    return nums[p];
  }

 private:
  int RandomizedPartition(std::vector<int>& nums, int p, int r) {
    int i = RandomInt(p, r + 1);
    std::swap(nums[i], nums[r]);
    return Partition(nums, p, r);
  }

  int Partition(std::vector<int>& nums, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; ++j) {
      if (nums[j] <= nums[r]) {
        i++;
        std::swap(nums[i], nums[j]);
      }
    }
    std::swap(nums[i + 1], nums[r]);
    return i + 1;
  }
};

void TestRecursive() {
  auto nums = std::vector<int>{2, 8, 7, 1, 3, 5, 6, 4};
  auto s = Solution();
  std::cout << s.Recursive(nums, 0, nums.size() - 1, 1) << std::endl;
}

void TestIterative() {
  auto nums = std::vector<int>{2, 8, 7, 1, 3, 5, 6, 4};
  auto s = Solution();
  std::cout << s.Iterative(nums, 0, nums.size() - 1, 1) << std::endl;
}

int main() {
  TestRecursive();
  TestIterative();
}
