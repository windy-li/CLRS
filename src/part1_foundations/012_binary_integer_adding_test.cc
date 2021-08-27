#include "part1_foundations/012_binary_integer_adding.h"

auto solution = Solution();

TEST(BinaryIntegerAddingTest, BinaryIntegerAdding) {
  std::vector<int> a = {1, 0, 1, 1, 1, 0};
  std::vector<int> b = {0, 1, 1, 1, 0, 0};
  std::vector<int> c = {1, 0, 0, 1, 0, 1, 0};
  std::vector<int> d = solution.BinaryIntegerAdding(a, b);
  for (int i = 0; i < c.size(); ++i) {
    EXPECT_EQ(c[i], d[i]) << "vectors c and d differ at index " << i;
  }
}

RUN_TESTS()
