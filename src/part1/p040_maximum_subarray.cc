#include "../clrs.h"

class Solution {
 public:
  std::tuple<int, int, int> BruteForceMaximumSubarray(std::vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = 0, max = INT_MIN;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        if (sum > max) {
          max = sum;
          start = i;
          end = j;
        }
      }
    }
    return std::make_tuple(start, end, max);
  }

  std::vector<int> DivideAndConquerMaximumSubarray(std::vector<int>& nums, int low, int high) {
    if (low == high) {
      return std::vector<int>{low, high, nums[low]};
    } else {
      int mid = (low + high) / 2;
      std::vector<int> left_result = DivideAndConquerMaximumSubarray(nums, low, mid);
      std::vector<int> right_result = DivideAndConquerMaximumSubarray(nums, mid + 1, high);
      std::vector<int> cross_result = MaxCrossingSubarray(nums, low, mid, high);
      int left_sum = left_result[2];
      int right_sum = right_result[2];
      int cross_sum = cross_result[2];
      if (left_sum >= right_sum && left_sum >= cross_sum) {
        return left_result;
      } else if (right_sum >= left_sum && right_sum >= cross_sum) {
        return right_result;
      } else {
        return cross_result;
      }
    }
  }

  int BottomUpMaximumSubarray(std::vector<int>& nums) {
    int n = nums.size();
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      max = std::max(max, sum);
      if (sum < 0) {
        sum = 0;
      }
    }
    return max;
  }

  std::vector<int> ExtendedBottomUpMaximumSubarray(std::vector<int>& nums) {
    int n = nums.size();
    int max = INT_MIN;
    int sum = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (max < sum) {
        max = sum;
        end = i;
      }
      if (sum < 0) {
        sum = 0;
        start = i + 1;
      }
    }
    return std::vector<int>{start, end, max};
  }

 private:
  std::vector<int> MaxCrossingSubarray(std::vector<int>& nums, int low, int mid, int high) {
    int sum = 0;
    int left_sum = INT_MIN;
    int max_left = mid;
    for (int i = mid; i >= low; i--) {
      sum += nums[i];
      if (sum > left_sum) {
        left_sum = sum;
        max_left = i;
      }
    }
    sum = 0;
    int right_sum = INT_MIN;
    int max_right = mid + 1;
    for (int j = mid + 1; j <= high; j++) {
      sum += nums[j];
      if (sum > right_sum) {
        right_sum = sum;
        max_right = j;
      }
    }
    return std::vector<int>{max_left, max_right, left_sum + right_sum};
  }
};

std::vector<int> GetSampleVector() {
  return std::vector<int>{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
}

void TestBruteForceMaximumSubarray() {
  std::vector<int> a = GetSampleVector();
  Solution s;
  auto [start, end, max] = s.BruteForceMaximumSubarray(a);
  std::cout << start << " " << end << " " << max << std::endl;
}

void TestDivideAndConquerMaximumSubarray() {
  std::vector<int> a = GetSampleVector();
  int n = a.size();
  Solution s;
  std::vector<int> result = s.DivideAndConquerMaximumSubarray(a, 0, n - 1);
  clrs::PrintVector(result);
}

void TestBottomUpMaximumSubarray() {
  std::vector<int> a = GetSampleVector();
  Solution s;
  std::cout << s.BottomUpMaximumSubarray(a) << std::endl;
}

void TestExtendedBottomUpMaximumSubarray() {
  std::vector<int> a = GetSampleVector();
  Solution s;
  std::vector<int> result = s.ExtendedBottomUpMaximumSubarray(a);
  clrs::PrintVector(result);
}

int main() {
  TestBruteForceMaximumSubarray();
  TestDivideAndConquerMaximumSubarray();
  TestBottomUpMaximumSubarray();
  TestExtendedBottomUpMaximumSubarray();
}
