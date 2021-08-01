#include "part1_foundations/073_random_sample.h"

Solution solution;

TEST(RandomSampleTest, RandomSample) {
  for (int i = 0; i < 10; ++i) {
    auto list = solution.RandomSample(3, 7);
    for (auto item : list) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }
}

TEST(RandomSampleTest, ReservoirSample) {}

RUN_TESTS()
