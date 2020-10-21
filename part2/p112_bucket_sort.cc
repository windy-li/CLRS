#include "clrs.h"

class Solution {
 public:
  void bucketSort(std::vector<double>& arr) {
    int n = arr.size();
    std::vector<double> buckets[n];
    for (int i = 0; i < n; ++i) {
      buckets[(int)(n * arr[i])].push_back(arr[i]);
    }
    int p = 0;
    for (int i = 0; i < n; ++i) {
      std::vector<double> list = buckets[i];
      //         insertionSort(list);
      sort(list.begin(), list.end());
      for (double j : list) {
        arr[p++] = j;
      }
    }
  }

 private:
  void insertionSort(std::vector<double>& list) {
    for (size_t j = 1; j < list.size(); ++j) {
      double key = list[j];
      size_t i = j - 1;
      while (i >= 0 && list[i] > key) {
        list[i + 1] = list[i];
        i--;
      }
      list[i + 1] = key;
    }
  }
};

int main() {
  std::vector<double> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.68};
  Solution s;
  s.bucketSort(arr);
  //  clrs::PrintArray(arr, arrLen);
}

/*
 * 0.12 0.17 0.21 0.26 0.39 0.68 0.72 0.78 0.94
 */
