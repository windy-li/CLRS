#include "part1_foundations/012_binary_integer_adding.h"

auto solution = Solution();

TEST(BinaryIntegerAddingTest, BinaryIntegerAdding) {
  auto a = std::vector<int>{1, 0, 1, 1, 1, 0};
  auto b = std::vector<int>{0, 1, 1, 1, 0, 0};
  auto c = std::vector<int>{1, 0, 0, 1, 0, 1, 0};
  std::vector<int> d = solution.BinaryIntegerAdding(a, b);
  for (int i = 0; i < c.size(); ++i) {
    EXPECT_EQ(c[i], d[i]) << "vectors c and d differ at index " << i;
  }
}

RUN_TESTS()
