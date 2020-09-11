#include "clrs.h"

class Solution {
 public:
  void ShellSort(std::vector<int> &a) {
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int j = gap; j < n; j++) {
        int key = a[j];
        int i = j - gap;
        while (i >= 0 && a[i] > key) {
          a[i + gap] = a[i];
          i -= gap;
        }
        a[i + gap] = key;
      }
    }
  }
};
