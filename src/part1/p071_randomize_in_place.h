#include "clrs.h"

class Solution {
 public:
  void RandomizeInPlace(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      swap(a[i], a[clrs::RandomInt(i, n)]);
    }
  }

  void PermuteBySorting(vector<int> &a) {
    int n = a.size();
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      p[i] = clrs::RandomInt(0, n * n * n);
    }
    SortForPermute(a, p);
  }

 private:
  void SortForPermute(vector<int> &a, vector<int> &p) {
    int n = a.size();
    for (int j = 1; j < n; j++) {
      int key = p[j];
      int i = j - 1;
      while (i >= 0 && p[i] > key) {
        p[i + 1] = p[i];
        --i;
      }
      p[i + 1] = key;
      swap(a[i + 1], a[j]);
    }
  }
};
