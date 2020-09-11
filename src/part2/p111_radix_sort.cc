#include "clrs.h"

class Solution {
public:
  void radixSort(int *arr, int len) {
    // Find the maximum number to know number of digits
    int max = maximum(arr, len);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
      countingSort(arr, len, exp);
//      clrs::PrintArray(arr, len);
    }
  }

private:
  void countingSort(int *arr, int len, int exp) {
    int k = 9;
    int count[k + 1];
    int output[k + 1];
    for (int i = 0; i <= k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
      count[(arr[i] / exp) % 10]++;
    }
    // Change count[i] so that count[i] now contains
    // actual position of this digit in output[]
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = len - 1; i >= 0; --i) {
      int x = (arr[i] / exp) % 10;
      output[count[x] - 1] = arr[i];
      count[x]--;
    }
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < len; ++i) {
      arr[i] = output[i];
    }
  }

  static int maximum(int *arr, int len) {
    int max = arr[0];
    for (int i = 1; i < len; ++i) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }
};

int main() {
  int arr[] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
  int len = 10;
  Solution s;
  s.radixSort(arr, len);
//  clrs::PrintArray(arr, len);
}

/*
 * 81 22 73 93 43 14 55 65 28 39
 * 14 22 28 39 43 55 65 73 81 93
 * 14 22 28 39 43 55 65 73 81 93
 */
