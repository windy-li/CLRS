#include "clrs.h"

class Solution {
 public:
  void SelectionSort(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
      int min = i;
      for (int j = i + 1; j < n; ++j) {
        if (a[j] < a[min]) {
          min = j;
        }
      }
      if (min != i) {
        std::swap(a[min], a[i]);
      }
    }
  }
};

void TestSelectionSort() {
  std::vector<int> a = {1, 3, 4, 2};
  Solution s;
  s.SelectionSort(a);
  clrs::PrintVector(a);
}

int main() { TestSelectionSort(); }
