#include "part1_foundations/012_binary_integer_adding.h"

#include "clrs.h"
#include "gtest/gtest.h"

Solution solution;

TEST(BinaryIntegerAddingTest, BinaryIntegerAdding) {
  std::vector<int> a = {1, 0, 1, 1, 1, 0};
  std::vector<int> b = {0, 1, 1, 1, 0, 0};
  std::vector<int> c = solution.BinaryIntegerAdding(a, b);
  clrs::PrintVector(c);
}
