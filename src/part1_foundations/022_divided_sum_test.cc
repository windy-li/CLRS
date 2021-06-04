#include "part1_foundations/022_divided_sum.h"

#include "clrs.h"
#include "gtest/gtest.h"

Solution solution;

TEST(DividecSumTest, CanDivide) {
  std::vector<int> nums = {8, 1, 4, 6, 9, 5};
  ASSERT_TRUE(solution.CanDivide(nums, 7));
  ASSERT_FALSE(solution.CanDivide(nums, 8));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
