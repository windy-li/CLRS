#include "../clrs.h"

class Solution {
 public:
  void RandomizeInPlace(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      std::swap(a[i], a[clrs::RandomInt(i, n)]);
    }
  }

  void PermuteBySorting(std::vector<int>& a) {
    int n = a.size();
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
      p[i] = clrs::RandomInt(0, n * n * n);
    }
    SortForPermute(a, p);
  }

 private:
  void SortForPermute(std::vector<int>& a, std::vector<int>& p) {
    int n = a.size();
    for (int j = 1; j < n; j++) {
      int key = p[j];
      int i = j - 1;
      while (i >= 0 && p[i] > key) {
        p[i + 1] = p[i];
        --i;
      }
      p[i + 1] = key;
      std::swap(a[i + 1], a[j]);
    }
  }
};

void TestRandomizeInPlace() {
  int n = 10;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i;
  }
  Solution s;
  s.RandomizeInPlace(a);
  clrs::PrintVector(a);
}

int main() { TestRandomizeInPlace(); }
