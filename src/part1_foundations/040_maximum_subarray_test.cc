#include "part1_foundations/040_maximum_subarray.h"

Solution solution;

std::vector<int> GetSampleVector() { return {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}; }

TEST(MaximumSubarrayTest, BruteForce) {
  std::vector<int> nums = GetSampleVector();
  auto [begin, end, max] = solution.BruteForce(nums);
  std::cout << begin << " " << end << " " << max << std::endl;
}

TEST(MaximumSubarrayTest, DivideAndConquer) {
  std::vector<int> nums = GetSampleVector();
  int n = nums.size();
  auto result = solution.DivideAndConquer(nums, 0, n - 1);
}

TEST(MaximumSubarrayTest, BottomUp) {
  std::vector<int> nums = GetSampleVector();
  std::cout << solution.BottomUp(nums) << std::endl;
}

TEST(MaximumSubarrayTest, ExtendedBottomUp) {
  std::vector<int> nums = GetSampleVector();
  auto result = solution.ExtendedBottomUp(nums);
}
