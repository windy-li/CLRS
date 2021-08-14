#include "clrs.h"

TEST(ClrsTest, TestRandomInt) {
  for (int i = 0; i < 20; ++i) {
    printf("%depth ", RandomInt(-100, 100));
  }
  printf("\n");
}

TEST(ClrsTest, TestRandomVector) {
  std::vector<int> v = RandomIntVector(0, 100, 10);
  PrintVector(v);
}

TEST(ClrsTest, TestDefaultRandomVector) {
  std::vector<int> v = RandomIntVector();
  PrintVector(v);
}

TEST(ClrsTest, TestRandomDouble) {
  for (int i = 0; i < 20; ++i) {
    printf("%f ", RandomDouble(0, 1));
  }
  printf("\n");
}

RUN_TESTS()
