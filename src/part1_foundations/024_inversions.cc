#include "clrs.h"

class Solution {
 public:
  int Inversions(std::vector<int>& nums, int p, int r) {
    if (p >= r) {
      return 0;
    }
    int q = (p + r) / 2;
    return Inversions(nums, p, q) + Inversions(nums, q + 1, r) + Merge(nums, p, q, r);
  }

 private:
  int Merge(std::vector<int>& nums, int p, int q, int r) {
    int count = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> left(n1);
    std::vector<int> right(n2);
    for (int i = 0; i < n1; ++i) {
      left[i] = nums[p + i];
    }
    for (int i = 0; i < n2; ++i) {
      right[i] = nums[q + 1 + i];
    }
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
      if (left[i] <= right[j]) {
        nums[k++] = left[i++];
      } else {
        count += n1 - i;
        for (int s = i; s < n1; ++s) {
          std::cout << left[s] << " " << right[j] << "\n";
        }
        nums[k++] = right[j++];
      }
    }
    while (i < n1) {
      nums[k++] = left[i++];
    }
    while (j < n2) {
      nums[k++] = right[j++];
    }
    return count;
  }
};

Solution solution;

void TestInversions() {
  std::vector<int> nums = {2, 3, 8, 6, 1};
  int n = nums.size();
  std::cout << solution.Inversions(nums, 0, n - 1) << " inversion pairs";
  clrs::PrintVector(nums);
}

int main() { TestInversions(); }
