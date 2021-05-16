#include "clrs.h"

class Solution {
 public:
  std::list<int> RandomSample(int m, int n) {
    if (m == 0) {
      return {};
    }
    std::list<int> s = RandomSample(m - 1, n - 1);
    int i = clrs::RandomInt(0, n + 1);
    if (!s.empty()) {
      if (std::find(s.begin(), s.end(), i) != s.end()) {
        s.push_back(n);
      } else {
        s.push_back(i);
      }
    }
    return s;
  }

  std::vector<int> ReservoirSample(std::vector<int>& nums, int m) {
    std::vector<int> s(m);
    for (int i = 0; i < nums.size(); ++i) {
      if (i < m) {
        s[i] = nums[i];
      } else {
        int temp = (int)(clrs::Random() * (i + 1));
        if (temp < m) {
          s[temp] = nums[i];
        }
      }
    }
    return s;
  }
};

Solution solution;

void TestRandomSample() {
  for (int i = 0; i < 10; ++i) {
    auto list = solution.RandomSample(3, 7);
    for (auto item : list) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }
}

void TestReservoirSample() {}

int main() {
  TestRandomSample();
  TestReservoirSample();
}
