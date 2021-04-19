#include "clrs.h"

class Solution {
 public:
  int BinarySearch(const std::vector<int>& nums, int key) {
    int n = nums.size();
    int begin = 0;
    int end = n - 1;
    while (begin <= end) {
      int mid = (begin + end) / 2;
      if (key == nums[mid]) {
        return mid;
      } else if (key < nums[mid]) {
        end = mid - 1;
      } else {
        begin = mid + 1;
      }
    }
    return -(begin + 1);
  }

  int RecursiveBinarySearch(const std::vector<int>& nums, int key, int begin, int end) {
    if (begin <= end) {
      int mid = (begin + end) / 2;
      if (key == nums[mid]) {
        return mid;
      } else if (key < nums[mid]) {
        return RecursiveBinarySearch(nums, key, begin, mid - 1);
      } else {
        return RecursiveBinarySearch(nums, key, mid + 1, end);
      }
    }
    return -(begin + 1);
  }
};

void TestBinarySearch() {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  int key1 = 2;
  int key2 = 7;
  Solution s;
  std::cout << s.BinarySearch(nums, key1) << std::endl;
  std::cout << s.BinarySearch(nums, key2) << std::endl;
}

void TestRecursiveBinarySearch() {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  int n = nums.size();
  int key1 = 2;
  int key2 = 7;
  Solution s;
  std::cout << s.RecursiveBinarySearch(nums, key1, 0, n - 1) << std::endl;
  std::cout << s.RecursiveBinarySearch(nums, key2, 0, n - 1) << std::endl;
}

int main() {
  TestBinarySearch();
  TestRecursiveBinarySearch();
}
