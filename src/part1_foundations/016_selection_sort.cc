#include "clrs.h"

class Solution {
 public:
  void SelectionSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      int min = i;
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] < nums[min]) {
          min = j;
        }
      }
      if (min != i) {
        std::swap(nums[min], nums[i]);
      }
    }
  }
};

Solution solution;

void TestSelectionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  solution.SelectionSort(nums);
  clrs::PrintVector(nums);
}

int main() { TestSelectionSort(); }
