#include "p012_binary_integer_adding.h"

void TestBinaryIntegerAdding() {
  std::vector<int> num_a = {1, 0, 1, 1, 1, 0};
  std::vector<int> num_b = {0, 1, 1, 1, 0, 0};
  Solution s;
  clrs::PrintVector(s.BinaryIntegerAdding(num_a, num_b));
}

int main() { TestBinaryIntegerAdding(); }
