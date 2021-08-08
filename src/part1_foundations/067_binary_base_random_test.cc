#include "part1_foundations/067_binary_base_random.h"

Solution solution;

TEST(BinaryBaseRandomTest, BinaryBaseRandom) {
  int a = 4, b = 9;
  for (int i = 0; i < 20; i++) {
    printf("%d ", solution.BinaryBaseRandom(a, b));
  }
}

RUN_TESTS()
