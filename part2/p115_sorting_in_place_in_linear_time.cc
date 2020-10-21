#include <algorithm>

class Solution {
public:
  static void ONAndStable(int *arr, int len, int *output) {
    int index = 0;
    for (int i = 0; i < len; i++) {
      if (arr[i] == 0) {
        output[index] = arr[i];
        index++;
      }
    }
    for (int i = 0; i < len; i++) {
      if (arr[i] == 1) {
        output[index] = arr[i];
        index++;
      }
    }
  }

  static void ONAndInPlace(int *arr, int len) {
    int index = 0;
    for (int i = 0; i < len; i++) {
      if (arr[i] == 0) {
        std::swap(arr[i], arr[index]);
        index++;
      }
    }
  }

  static void stableAndInPlace(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
      for (int j = len - 1; j > i; j--) {
        if (arr[j] < arr[j - 1]) {
          std::swap(arr[j], arr[j - 1]);
        }
      }
    }
  }

  static void countingSortInPlace(int *a, int len, int k) {
    int c[k + 1];
    for (int i = 0; i < k; i++) {
      c[i] = 0;
    }
    for (int i = 0; i < len; i++) {
      c[a[i]]++;
    }
    for (int i = 1; i <= k; i++) {
      c[i] += c[i - 1];
    }
    for (int i = 0; i < len; i++) {
      a[i] = 0;
    }
    for (int i = k; i > 0; i--) {
      while (c[i] != c[i - 1]) {
        a[c[i] - 1] = i;
        c[i]--;
      }
    }
  }
};

int main() {
  return 0;
}
