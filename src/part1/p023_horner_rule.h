#include "clrs.h"

class Solution {
 public:
  int HornerRule(std::vector<int>& a, int x) {
    int n = a.size();
    int y = 0;
    for (int i = n - 1; i >= 0; i--) {
      y = a[i] + x * y;
    }
    return y;
  }

  int NaivePolynomialEvaluation(std::vector<int>& a, int x) {
    int n = a.size();
    int y[n];
    y[0] = 1;
    for (int i = 1; i < n; i++) {
      y[i] = 1;
      for (int j = 0; j < i; j++) {
        y[i] *= x;
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i] * y[i];
    }
    return sum;
  }
};
