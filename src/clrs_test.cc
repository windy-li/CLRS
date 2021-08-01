#include "clrs.h"

TEST(ClrsTest, TestRandomInt) {
  for (int i = 0; i < 20; ++i) {
    printf("%d ", Random::Int(-100, 100));
  }
  printf("\n");
}

TEST(ClrsTest, TestRandomVector) {
  std::vector<int> v = Random::Vector(0, 100, 10);
  Format::Println(v);
}

TEST(ClrsTest, TestDefaultRandomVector) {
  std::vector<int> v = Random::Vector();
  Format::Println(v);
}

TEST(ClrsTest, TestRandomDouble) {
  for (int i = 0; i < 20; ++i) {
    printf("%f ", Random::Double());
  }
  printf("\n");
}

RUN_TESTS()
