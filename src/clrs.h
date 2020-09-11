#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

//typedef int error;
#define error int

using namespace std;

namespace clrs {

template <typename T>
void PrintVector(const vector<T> &vec) {
  int n = vec.size();
  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << vec[i];
    if (i != n - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int RandomInt(int include, int exclude) {
  random_device rd;
  auto gen = default_random_engine(rd());
  uniform_int_distribution<int> dis(include, exclude - 1);
  return dis(gen);
}

double Random() {
  random_device rd;
  auto gen = default_random_engine(rd());
  uniform_real_distribution<double> dis(0.0, 1.0);
  return dis(gen);
}

}  // namespace clrs
