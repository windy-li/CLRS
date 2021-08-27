#include "part1_foundations/071_randomize_in_place.h"

Solution solution;

TEST(RandomizeInPlaceTest, RandomizeInPlace) {
  int n = 10;
  auto nums = std::vector<int>(n);
  for (int i = 0; i < n; ++i) {
    nums[i] = i;
  }
  solution.RandomizeInPlace(nums);
  PrintVector(nums);
}

RUN_TESTS()
