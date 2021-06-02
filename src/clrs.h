#ifndef CLRS_CLRS_H
#define CLRS_CLRS_H

#include <algorithm>
#include <cmath>
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

namespace clrs {

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

int RandomInt(int left_bound_included, int right_bound_excluded) {
  std::random_device rd;
  auto gen = std::default_random_engine(rd());
  std::uniform_int_distribution<int> dis(left_bound_included, right_bound_excluded - 1);
  return dis(gen);
}

double Random() {
  std::random_device rd;
  auto gen = std::default_random_engine(rd());
  std::uniform_real_distribution<double> dis(0.0, 1.0);
  return dis(gen);
}

void PrintBorder() { std::cout << "------------------------------" << std::endl; }

std::vector<int> RandomVector() {
  int n = 1000;
  int low = 0;
  int high = 100;
  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    vec[i] = RandomInt(low, high);
  }
  return vec;
}

}  // namespace clrs

#endif  // CLRS_CLRS_H
