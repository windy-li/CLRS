#include "clrs.h"

class Solution {
 public:
  std::tuple<int, int, int> BruteForceMaximumSubarray(const std::vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = 0, max = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i; j < n; ++j) {
        sum += nums[j];
        if (sum > max) {
          max = sum;
          start = i;
          end = j;
        }
      }
    }
    return {start, end, max};
  }

  std::tuple<int, int, int> DivideAndConquerMaximumSubarray(const std::vector<int>& nums, int low, int high) {
    if (low == high) {
      return {low, high, nums[low]};
    }
    int mid = (low + high) / 2;
    auto left_result = DivideAndConquerMaximumSubarray(nums, low, mid);
    auto right_result = DivideAndConquerMaximumSubarray(nums, mid + 1, high);
    auto cross_result = MaxCrossingSubarray(nums, low, mid, high);
    int left_sum = std::get<2>(left_result);
    int right_sum = std::get<2>(right_result);
    int cross_sum = std::get<2>(cross_result);
    if (left_sum >= right_sum && left_sum >= cross_sum) {
      return left_result;
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
      return right_result;
    } else {
      return cross_result;
    }
  }

  int BottomUpMaximumSubarray(const std::vector<int>& nums) {
    int n = nums.size();
    int max = std::numeric_limits<int>::min();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      max = std::max(max, sum);
      if (sum < 0) {
        sum = 0;
      }
    }
    return max;
  }

  std::tuple<int, int, int> ExtendedBottomUpMaximumSubarray(const std::vector<int>& nums) {
    int n = nums.size();
    int max = std::numeric_limits<int>::min();
    int sum = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; ++i) {
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
    return {start, end, max};
  }

 private:
  std::tuple<int, int, int> MaxCrossingSubarray(const std::vector<int>& nums, int low, int mid, int high) {
    int sum = 0;
    int left_sum = std::numeric_limits<int>::min();
    int left_bound = mid;
    for (int i = mid; i >= low; --i) {
      sum += nums[i];
      if (sum > left_sum) {
        left_sum = sum;
        left_bound = i;
      }
    }
    sum = 0;
    int right_sum = std::numeric_limits<int>::min();
    int right_bound = mid + 1;
    for (int j = mid + 1; j <= high; ++j) {
      sum += nums[j];
      if (sum > right_sum) {
        right_sum = sum;
        right_bound = j;
      }
    }
    return {left_bound, right_bound, left_sum + right_sum};
  }
};

std::vector<int> GetSampleVector() { return {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}; }

void TestBruteForceMaximumSubarray() {
  std::vector<int> nums = GetSampleVector();
  Solution s;
  auto [start, end, max] = s.BruteForceMaximumSubarray(nums);
  std::cout << start << " " << end << " " << max << std::endl;
}

void TestDivideAndConquerMaximumSubarray() {
  std::vector<int> nums = GetSampleVector();
  int n = nums.size();
  Solution s;
  auto result = s.DivideAndConquerMaximumSubarray(nums, 0, n - 1);
}

void TestBottomUpMaximumSubarray() {
  std::vector<int> nums = GetSampleVector();
  Solution s;
  std::cout << s.BottomUpMaximumSubarray(nums) << std::endl;
}

void TestExtendedBottomUpMaximumSubarray() {
  std::vector<int> nums = GetSampleVector();
  Solution s;
  auto result = s.ExtendedBottomUpMaximumSubarray(nums);
}

int main() {
  TestBruteForceMaximumSubarray();
  TestDivideAndConquerMaximumSubarray();
  TestBottomUpMaximumSubarray();
  TestExtendedBottomUpMaximumSubarray();
}
