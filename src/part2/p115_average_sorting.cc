#include <algorithm>

class Solution {
public:
  static void kSort(int *arr, int k, int p, int r) {
    if (r - p >= k) {
      int q = Partition(arr, p, r);
      kSort(arr, k, p, q - 1);
      kSort(arr, k, q + 1, r);
    }
  }

private:
  static int Partition(int *arr, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; j++) {
      if (arr[j] <= arr[r]) {
        i++;
        std::swap(arr[i], arr[j]);
      }
    }
    std::swap(arr[i + 1], arr[r]);
    return i + 1;
  }
};

int main() {
  return 0;
}
