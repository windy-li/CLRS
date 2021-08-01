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

// 返回[a, b]区间的随机数
int RandomInt(int a, int b) {
  static std::random_device rd;
  static std::mt19937 engine(rd());
  static std::uniform_int_distribution<int> distribution(a, b);
  return distribution(engine);
}

// 返回元素个数为n的数列，且每个元素是[a, b]区间的随机数
std::vector<int> RandomVector(int a, int b, int n) {
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = RandomInt(a, b);
  }
  return v;
}

// 返回元素个数为1000的数列，且每个元素是[-100, 100]区间的随机数
std::vector<int> DefaultRandomVector() { return RandomVector(-100, 100, 1000); }

// 返回[0, 1)区间的小数
double Random() {
  static std::random_device rd;
  static std::mt19937 engine(rd());
  static std::uniform_real_distribution<double> distribution(0, 1);
  return distribution(engine);
}

// 打印一个数列
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
  std::cout << "]\n";
}

void PrintBorder() { std::cout << "------------------------------" << std::endl; }

}  // namespace clrs

#endif  // CLRS_CLRS_H
