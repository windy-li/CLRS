#include "part1_foundations/022_divided_sum.h"

Solution solution;

TEST(DividecSumTest, CanDivide) {
  auto nums = std::vector<int>{8, 1, 4, 6, 9, 5};
  ASSERT_TRUE(solution.CanDivide(nums, 7));
  ASSERT_FALSE(solution.CanDivide(nums, 8));
}

RUN_TESTS()
