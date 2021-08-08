#include "part1_foundations/040_maximum_subarray.h"

Solution solution;

std::vector<int> SampleVector() { return {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}; }

TEST(MaximumSubarrayTest, BruteForce) {
  std::vector<int> nums = SampleVector();
  auto [begin, end, max] = solution.BruteForce(nums);
  printf("%d %d %d \n", begin, end, max);
}

TEST(MaximumSubarrayTest, DivideAndConquer) {
  std::vector<int> nums = SampleVector();
  int n = nums.size();
  auto result = solution.DivideAndConquer(nums, 0, n - 1);
}

TEST(MaximumSubarrayTest, BottomUp) {
  std::vector<int> nums = SampleVector();
  printf("%d\n", solution.BottomUp(nums));
}

TEST(MaximumSubarrayTest, ExtendedBottomUp) {
  std::vector<int> nums = SampleVector();
  auto result = solution.ExtendedBottomUp(nums);
}

RUN_TESTS()
