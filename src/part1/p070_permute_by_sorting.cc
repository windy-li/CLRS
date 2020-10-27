#include "../clrs.h"

class Solution {
 public:
  void PermuteBySorting(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      p[i] = clrs::RandomInt(0, n * n * n);
    }
    SortForPermute(nums, p);
  }

 private:
  void SortForPermute(std::vector<int>& nums, std::vector<int>& p) {
    int n = nums.size();
    for (int j = 1; j < n; ++j) {
      int key = p[j];
      int i = j - 1;
      while (i >= 0 && p[i] > key) {
        p[i + 1] = p[i];
        --i;
      }
      p[i + 1] = key;
      std::swap(nums[i + 1], nums[j]);
    }
  }
};

int main() {
  int n = 10;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i;
  }
  Solution s;
  s.PermuteBySorting(a);
  clrs::PrintVector(a);
}
