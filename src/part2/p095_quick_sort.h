#include "clrs.h"

class Solution {
 public:
  void QuickSort(vector<int> &nums, int p, int r) {
    if (p < r) {
      int q = Partition(nums, p, r);
      QuickSort(nums, p, q - 1);
      QuickSort(nums, q + 1, r);
    }
  }

  void IterativeQuickSort(vector<int> &nums, int p, int r) {
    int s[r - p + 1];
    int top = -1;
    s[++top] = p;
    s[++top] = r;
    while (top >= 0) {
      r = s[top--];
      p = s[top--];
      int pivot = Partition(nums, p, r);
      if (pivot - p > 1) {
        s[++top] = p;
        s[++top] = pivot - 1;
      }
      if (r - pivot > 1) {
        s[++top] = pivot + 1;
        s[++top] = r;
      }
    }
  }

  void RandomizedQuickSort(vector<int> &nums, int p, int r) {
    if (p < r) {
      int q = RandomizedPartition(nums, p, r);
      RandomizedQuickSort(nums, p, q - 1);
      RandomizedQuickSort(nums, q + 1, r);
    }
  }

  void HoareQuickSort(vector<int> &nums, int p, int r) {
    if (p < r) {
      int q = HoarePartition(nums, p, r);
      HoareQuickSort(nums, p, q);
      HoareQuickSort(nums, q + 1, r);
    }
  }

  void TailRecursiveQuickSort(vector<int> &nums, int p, int r) {
    while (p < r) {
      int q = Partition(nums, p, r);
      TailRecursiveQuickSort(nums, p, q - 1);
      p = q + 1;
    }
  }

  void ModifiedTailRecursiveQuickSort(vector<int> &nums, int p, int r) {
    while (p < r) {
      int q = Partition(nums, p, r);
      if (q < (r - p) / 2) {
        ModifiedTailRecursiveQuickSort(nums, p, q - 1);
        p = q + 1;
      } else {
        ModifiedTailRecursiveQuickSort(nums, q + 1, r);
        r = q - 1;
      }
    }
  }

  void MedianOfThreeQuickSort(vector<int> &nums, int p, int r) {
    if (p < r) {
      int q = MedianOfThreePartition(nums, p, r);
      MedianOfThreeQuickSort(nums, p, q - 1);
      MedianOfThreeQuickSort(nums, q + 1, r);
    }
  }

  void ThreeWayQuickSort(vector<int> &nums, int p, int r) {
    if (p < r) {
      vector<int> pivots = ThreeWayPartition(nums, p, r);
      ThreeWayQuickSort(nums, p, pivots[0]);
      ThreeWayQuickSort(nums, pivots[1], r);
    }
  }

 private:
  int Partition(vector<int> &a, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; j++) {
      if (a[j] <= a[r]) {
        i++;
        swap(a[i], a[j]);
      }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
  }

  int RandomizedPartition(vector<int> &a, int p, int r) {
    int i = clrs::RandomInt(p, r + 1);
    swap(a[i], a[r]);
    return Partition(a, p, r);
  }

  int HoarePartition(vector<int> &a, int p, int r) {
    int x = a[p];
    int i = p - 1;
    int j = r + 1;
    while (true) {
      do {
        i++;
      } while (a[i] < x);
      do {
        j--;
      } while (a[j] > x);
      if (i < j) {
        swap(a[i], a[j]);
      } else {
        return j;
      }
    }
  }

  int MedianOfThreePartition(vector<int> &arr, int p, int r) {
    int a = p + clrs::RandomInt(0, r - p + 1);
    int b = p + clrs::RandomInt(0, r - p + 1);
    int c = p + clrs::RandomInt(0, r - p + 1);
    int m = MedianOfThree(arr, a, b, c);
    swap(arr[m], arr[r]);
    return Partition(arr, p, r);
  }

  int MedianOfThree(vector<int> &nums, int a, int b, int c) {
    if (nums[a] < nums[b]) {
      if (nums[b] < nums[c]) {
        return b;
      } else if (nums[a] < nums[c]) {
        return c;
      } else {
        return a;
      }
    } else {
      if (nums[b] > nums[c]) {
        return b;
      } else if (nums[a] > nums[c]) {
        return c;
      } else {
        return a;
      }
    }
  }

  vector<int> ThreeWayPartition(vector<int> &a, int p, int r) {
    int lt = p - 1;
    int gt = r;
    int i = p;
    int pivot = a[r];
    while (i < gt) {
      if (a[i] < pivot) {
        lt++;
        swap(a[i], a[lt]);
        i++;
      } else if (a[i] > pivot) {
        gt--;
        swap(a[i], a[gt]);
      } else {
        i++;
      }
    }
    swap(a[r], a[gt]);
    return vector<int>{lt, gt + 1};
  }
};
