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

// 返回[a, b]区间的随机整数
int RandomInt(int a, int b) {
  static std::random_device rd;
  static std::mt19937 engine(rd());
  static std::uniform_int_distribution<int> distribution(a, b);
  return distribution(engine);
}

// 返回[a, b)区间的随机实数
double RandomDouble(double a, double b) {
  static std::random_device rd;
  static std::mt19937 engine(rd());
  static std::uniform_real_distribution<double> distribution(a, b);
  return distribution(engine);
}

// 返回元素个数为n的数列，且每个元素是[a, b]区间的随机整数
std::vector<int> RandomIntVector(int a, int b, int n) {
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = RandomInt(a, b);
  }
  return v;
}

// 返回元素个数为n的数列，且每个元素是[a, b)区间的随机实数
std::vector<double> RandomDoubleVector(double a, double b, int n) {
  auto v = std::vector<double>(n);
  for (int i = 0; i < n; ++i) {
    v[i] = RandomDouble(a, b);
  }
  return v;
}

// 返回元素个数为1000的数列，且每个元素是[-100, 100]区间的随机整数
std::vector<int> RandomIntVector() { return RandomIntVector(-100, 100, 1000); }

// 返回元素个数为1000的数列，且每个元素是[0, 1)区间的随机实数
std::vector<double> RandomDoubleVector() { return RandomDoubleVector(0, 1, 1000); }

// 打印一个数列
template <typename T>
void PrintVector(std::vector<T>& v) {
  int n = v.size();
  std::cout << "[";
  for (int i = 0; i < n; ++i) {
    std::cout << v[i];
    if (i != n - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
}

#endif  // CLRS_CLRS_H
