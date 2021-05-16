#include "clrs.h"

class Solution {
 public:
  int HornerRule(std::vector<int>& nums, int x) {
    int n = nums.size();
    int y = 0;
    for (int i = n - 1; i >= 0; --i) {
      y = nums[i] + x * y;
    }
    return y;
  }

  int NaivePolynomialEvaluation(std::vector<int>& nums, int x) {
    int n = nums.size();
    int y[n];
    y[0] = 1;
    for (int i = 1; i < n; ++i) {
      y[i] = 1;
      for (int j = 0; j < i; ++j) {
        y[i] *= x;
      }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i] * y[i];
    }
    return sum;
  }
};

Solution solution;

void TestHornerRule() {
  std::vector<int> nums = {1, 2, 3};
  int x = 2;
  std::cout << solution.HornerRule(nums, x) << std::endl;
}

void TestNaivePolynomialEvaluation() {
  std::vector<int> nums = {1, 2, 3};
  int x = 2;
  std::cout << solution.NaivePolynomialEvaluation(nums, x) << std::endl;
}

int main() {
  TestHornerRule();
  TestNaivePolynomialEvaluation();
}
