#include "clrs.h"

class Solution {
 public:
  int Inversions(std::vector<int> &a, int p, int r) {
    if (p < r) {
      int q = (p + r) / 2;
      return Inversions(a, p, q) + Inversions(a, q + 1, r) + Merge(a, p, q, r);
    }
    return 0;
  }

 private:
  int Merge(std::vector<int> &a, int p, int q, int r) {
    int inv = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> left(n1);
    std::vector<int> right(n2);
    for (int i = 0; i < n1; i++) {
      left[i] = a[p + i];
    }
    for (int i = 0; i < n2; i++) {
      right[i] = a[q + 1 + i];
    }
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
      if (left[i] <= right[j]) {
        a[k++] = left[i++];
      } else {
        inv += n1 - i;
        for (int s = i; s < n1; s++) {
          cout << left[s] << " " << right[j] << "\n";
        }
        a[k++] = right[j++];
      }
    }
    while (i < n1) {
      a[k++] = left[i++];
    }
    while (j < n2) {
      a[k++] = right[j++];
    }
    return inv;
  }
};
