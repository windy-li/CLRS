#include "part1_foundations/073_random_sample.h"

Solution solution;

TEST(RandomSampleTest, RandomSample) {
  for (int i = 0; i < 10; ++i) {
    std::list<int> list = solution.RandomSample(3, 7);
    for (int item : list) {
      printf("%d ", item);
    }
    printf("\n");
  }
}

TEST(RandomSampleTest, ReservoirSample) {}

RUN_TESTS()
