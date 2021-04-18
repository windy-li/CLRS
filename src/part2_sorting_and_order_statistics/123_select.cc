#include "clrs.h"

class Solution {
 public:
  int Select(std::vector<int>& nums, int p, int r, int i) {
    if (p == r) {
      return nums[p];
    }
    int n = r - p + 1;
    int g = (n + 4) / 5;
    std::vector<int> medians(g);
    for (int j = 0; j < g; ++j) {
      int start = p + j * 5;
      int end = (start + 4 > r) ? r : (start + 4);
      medians[j] = GetMedian(nums, start, end);
    }
    int med_of_med = Select(medians, 0, g - 1, (g + 1) / 2);
    int q = Partition(nums, p, r, med_of_med);
    int k = q - p + 1;
    if (i == k) {
      return nums[q];
    } else if (i < k) {
      return Select(nums, p, q - 1, i);
    } else {
      return Select(nums, q + 1, r, i - k);
    }
  }

 private:
  int GetMedian(std::vector<int>& nums, int start, int end) {
    for (int j = start + 1; j <= end; j++) {
      int key = nums[j];
      int i = j - 1;
      while (i >= start && nums[i] > key) {
        nums[i + 1] = nums[i];
        i--;
      }
      nums[i + 1] = key;
    }
    return nums[(start + end) / 2];
  }

  int Partition(std::vector<int>& nums, int p, int r, int pivot) {
    int i = p - 1;
    for (int j = p; j <= r; ++j) {
      if (nums[j] <= pivot) {
        i++;
        std::swap(nums[i], nums[j]);
      }
    }
    return i;
  }
};

void TestSelect() {
  Solution s;
  std::vector<int> nums = {2, 8, 7, 1, 3, 5, 6, 4};
  std::cout << s.Select(nums, 0, nums.size() - 1, 4) << std::endl;
}

int main() { TestSelect(); }
