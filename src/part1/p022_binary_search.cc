#include "clrs.h"

class Solution {
 public:
  int BinarySearch(std::vector<int>& nums, int k) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (k == nums[mid]) {
        return mid;
      } else if (k < nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -(low + 1);
  }

  int RecursiveBinarySearch(std::vector<int>& nums, int key, int low, int high) {
    if (low <= high) {
      int mid = (low + high) / 2;
      if (key == nums[mid]) {
        return mid;
      } else if (key < nums[mid]) {
        return RecursiveBinarySearch(nums, key, low, mid - 1);
      } else {
        return RecursiveBinarySearch(nums, key, mid + 1, high);
      }
    }
    return -(low + 1);
  }
};

void TestBinarySearch() {
  std::vector<int> a = {1, 2, 3, 4, 5, 6};
  int k1 = 2;
  int k2 = 7;
  Solution s;
  std::cout << s.BinarySearch(a, k1) << std::endl;
  std::cout << s.BinarySearch(a, k2) << std::endl;
}

void TestRecursiveBinarySearch() {
  std::vector<int> a = {1, 2, 3, 4, 5, 6};
  int n = a.size();
  int k1 = 2;
  int k2 = 7;
  Solution s;
  std::cout << s.RecursiveBinarySearch(a, k1, 0, n - 1) << std::endl;
  std::cout << s.RecursiveBinarySearch(a, k2, 0, n - 1) << std::endl;
}

int main() {
  TestBinarySearch();
  TestRecursiveBinarySearch();
}
