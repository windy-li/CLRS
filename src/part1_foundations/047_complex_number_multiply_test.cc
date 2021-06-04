#include "part1_foundations/047_complex_number_multiply.h"

Solution solution;

TEST(ComplexNumberMultiplyTest, ComplexNumberMultiply) {
  std::vector<int> result = solution.ComplexNumberMultiply(1, 2, 3, 4);
  clrs::PrintVector(result);
}
