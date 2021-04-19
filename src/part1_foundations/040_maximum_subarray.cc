#include "clrs.h"

class Solution {
 public:
  std::tuple<int, int, int> BruteForce(const std::vector<int>& nums) {
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

  std::tuple<int, int, int> DivideAndConquer(const std::vector<int>& nums, int left_bound, int right_bound) {
    if (left_bound == right_bound) {
      return {left_bound, right_bound, nums[left_bound]};
    }
    int middle = (left_bound + right_bound) / 2;
    auto left_result = DivideAndConquer(nums, left_bound, middle);
    auto right_result = DivideAndConquer(nums, middle + 1, right_bound);
    auto cross_result = MaxCrossingSubarray(nums, left_bound, middle, right_bound);
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

  int BottomUp(const std::vector<int>& nums) {
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

  std::tuple<int, int, int> ExtendedBottomUp(const std::vector<int>& nums) {
    int n = nums.size();
    int max = std::numeric_limits<int>::min();
    int sum = 0;
    int begin = 0;
    int end = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      if (max < sum) {
        max = sum;
        end = i;
      }
      if (sum < 0) {
        sum = 0;
        begin = i + 1;
      }
    }
    return {begin, end, max};
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

Solution s;
std::vector<int> GetSampleVector() { return {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}; }

void TestBruteForce() {
  std::vector<int> nums = GetSampleVector();
  auto [begin, end, max] = s.BruteForce(nums);
  std::cout << begin << " " << end << " " << max << std::endl;
}

void TestDivideAndConquer() {
  std::vector<int> nums = GetSampleVector();
  int n = nums.size();
  auto result = s.DivideAndConquer(nums, 0, n - 1);
}

void TestBottomUp() {
  std::vector<int> nums = GetSampleVector();
  std::cout << s.BottomUp(nums) << std::endl;
}

void TestExtendedBottomUp() {
  std::vector<int> nums = GetSampleVector();
  auto result = s.ExtendedBottomUp(nums);
}

int main() {
  TestBruteForce();
  TestDivideAndConquer();
  TestBottomUp();
  TestExtendedBottomUp();
}
