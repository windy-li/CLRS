#include "part1_foundations/012_binary_integer_adding.h"

Solution solution;

TEST(BinaryIntegerAddingTest, BinaryIntegerAdding) {
  std::vector<int> a = {1, 0, 1, 1, 1, 0};
  std::vector<int> b = {0, 1, 1, 1, 0, 0};
  std::vector<int> x = {1, 0, 0, 1, 0, 1, 0};
  std::vector<int> y = solution.BinaryIntegerAdding(a, b);
  for (int i = 0; i < x.size(); ++i) {
    EXPECT_EQ(x[i], y[i]) << "vectors x and y differ at index " << i;
  }
}
