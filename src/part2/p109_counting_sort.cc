#include "clrs.h"

class Solution {
public:
  static void countingSort(int *arr, int len, int k, int *output) {
    int count[k + 1];
    for (int i = 0; i <= k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
      count[arr[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    for (int i = len - 1; i >= 0; --i) {
      int x = arr[i];
      output[count[x] - 1] = x;
      count[x]--;
    }
  }

  static int countingRange(int *arr, int len, int k, int left, int right) {
    int count[k + 1];
    for (int i = 0; i < k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
      count[arr[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    if (left <= 0) {
      return count[right];
    } else {
      return count[right] - count[left - 1];
    }
  }
};

void testCountingSort() {
  int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
  int len = 8;
  int k = 5;
  int output[len];
  Solution::countingSort(arr, len, k, output);
//  clrs::PrintArray(output, len);
}

void testCountingRange() {
  int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
  int len = 8;
  int k = 5;
  int left = 2;
  int right = 3;
  std::cout << Solution::countingRange(arr, len, k, left, right);
}

int main() {
  testCountingSort();
  testCountingRange();
  return 0;
}

/*
 * 0 0 2 2 3 3 3 5
 * 5
 */
