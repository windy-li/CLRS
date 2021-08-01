#include "clrs.h"

TEST(ClrsTest, TestRandomInt) {
  for (int i = 0; i < 20; ++i) {
    printf("%d ", clrs::RandomInt(0, 100));
  }
  printf("\n");
}

TEST(ClrsTest, TestRandomVector) {
  std::vector<int> v = clrs::RandomVector(0, 100, 10);
  clrs::PrintVector(v);
}

TEST(ClrsTest, TestDefaultRandomVector) {
  std::vector<int> v = clrs::DefaultRandomVector();
  clrs::PrintVector(v);
}

TEST(ClrsTest, TestRandom) {
  for (int i = 0; i < 20; ++i) {
    printf("%f ", clrs::Random());
  }
  printf("\n");
}

RUN_TESTS()
