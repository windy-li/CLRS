#include "clrs.h"

class Solution {
 public:
  void BruteForceJugPair(std::vector<int>& red, std::vector<int>& blue) {
    int n = red.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (red[i] == blue[j]) {
          std::swap(blue[i], blue[j]);
        }
      }
    }
  }

  void JugSort(std::vector<int>& red, std::vector<int>& blue, int p, int r) {
    if (p < r) {
      int pivot = RandomInt(p, r);
      std::swap(red[pivot], red[r]);
      int q = Partition(blue, p, r, red[r]);
      Partition(red, p, r, blue[q]);
      JugSort(red, blue, p, q - 1);
      JugSort(red, blue, q + 1, r);
    }
  }

 private:
  int Partition(std::vector<int>& nums, int p, int r, int key) {
    int i = p - 1;
    for (int j = p; j <= r; ++j) {
      if (nums[j] < key) {
        i++;
        std::swap(nums[i], nums[j]);
      }
    }
    for (int j = i + 1; j <= r; ++j) {
      if (nums[j] == key) {
        i++;
        std::swap(nums[i], nums[j]);
        break;
      }
    }
    return i;
  }
};

void TestBruteForceJugPair() {
  auto red = std::vector<int>{1, 2, 3, 4, 5, 99, 7, 8, 9, 10};
  auto blue = std::vector<int>{10, 9, 8, 7, 99, 5, 4, 3, 2, 1};
  auto s = Solution();
  s.BruteForceJugPair(red, blue);
  PrintVector(red);
  PrintVector(blue);
}

void TestJugSort() {
  auto red = std::vector<int>{1, 2, 3, 4, 5, 99, 7, 8, 9, 10};
  auto blue = std::vector<int>{10, 9, 8, 7, 99, 5, 4, 3, 2, 1};
  auto s = Solution();
  s.JugSort(red, blue, 0, 9);
  PrintVector(red);
  PrintVector(blue);
}

int main() {
  TestBruteForceJugPair();
  TestJugSort();
}
