#include "clrs.h"

TEST(ClrsTest, TestRandomInt) {
  for (int i = 0; i < 10; ++i) {
    printf("%d ", clrs::RandomInt(0, 100));
  }
  printf("\n");
}

TEST(ClrsTest, TestRandomVector) {
  std::vector<int> v = clrs::RandomVector(0, 100, 10);
  clrs::PrintVector(v);
}

RUN_TESTS()
