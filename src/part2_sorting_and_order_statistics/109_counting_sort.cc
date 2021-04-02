#include "clrs.h"

class Solution {
 public:
  std::vector<int> CountingSort(std::vector<int>& a, int k) {
    int n = a.size();
    std::vector<int> b(n);
    std::vector<int> count(k + 1);
    for (int i = 0; i <= k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      count[a[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
      int x = a[i];
      b[count[x] - 1] = x;
      count[x]--;
    }
    return b;
  }

  int CountingRange(std::vector<int>& a, int k, int left, int right) {
    int n = a.size();
    std::vector<int> count(k + 1);
    for (int i = 0; i < k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      count[a[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    if (left <= 0) {
      return count[right];
    } else {
      return count[right] - count[left - 1];
    }
  }
};

void TestCountingSort() {
  std::vector<int> a = {2, 5, 3, 0, 2, 3, 0, 3};
  int k = 5;
  Solution s;
  std::vector<int> b = s.CountingSort(a, k);
  clrs::PrintVector(b);
}

void TestCountingRange() {
  std::vector<int> a = {2, 5, 3, 0, 2, 3, 0, 3};
  int k = 5;
  int left = 2;
  int right = 3;
  Solution s;
  std::cout << s.CountingRange(a, k, left, right) << std::endl;
}

int main() {
  TestCountingSort();
  TestCountingRange();
}

/*
 * 0 0 2 2 3 3 3 5
 * 5
 */
