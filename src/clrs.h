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

namespace clrs {

class Random {
 public:
  static int Get(int left, int right) {
    std::uniform_int_distribution<int> distribution(left, right - 1);
    std::default_random_engine engine = GetEngine();
    return distribution(engine);
  }

  static double Get() {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::default_random_engine engine = GetEngine();
    return distribution(engine);
  }

  static std::vector<int> Vector() {
    int n = 1000;
    int low = 0;
    int high = 100;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
      vec[i] = Get(low, high);
    }
    return vec;
  }

 private:
  static std::default_random_engine GetEngine() {
    std::random_device device;
    std::default_random_engine engine(device());
    return engine;
  }
};

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
