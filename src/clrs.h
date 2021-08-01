#ifndef CLRS_CLRS_H
#define CLRS_CLRS_H

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

#define TEST(test_suite_name, test_name) GTEST_TEST(test_suite_name, test_name) /* NOLINT */

#define RUN_TESTS()                         \
  int main(int argc, char* argv[]) {        \
    ::testing::InitGoogleTest(&argc, argv); \
    return RUN_ALL_TESTS();                 \
  }

namespace clrs {

// [a, b]
int RandomInt(int a, int b) {
  static std::random_device rd;
  static std::mt19937 engine(rd());
  static std::uniform_int_distribution<int> distribution(a, b);
  return distribution(engine);
}

// [a, b]
std::vector<int> RandomVector(int a, int b, int size) {
  std::vector<int> v(size);
  for (int i = 0; i < size; ++i) {
    v[i] = RandomInt(a, b);
  }
  return v;
}

std::vector<int> DefaultRandomVector() { return RandomVector(0, 100, 100); }

// [0, 1)
double Random() {
  static std::random_device rd;
  static std::mt19937 engine(rd());
  static std::uniform_real_distribution<double> distribution(0, 1);
  return distribution(engine);
}

template <typename T>
void PrintVector(std::vector<T>& vec) {
  int n = vec.size();
  std::cout << "[";
  for (int i = 0; i < n; ++i) {
    std::cout << vec[i];
    if (i != n - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

void PrintBorder() { std::cout << "------------------------------" << std::endl; }

}  // namespace clrs

#endif  // CLRS_CLRS_H
