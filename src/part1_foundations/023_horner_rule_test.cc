#include "part1_foundations/023_horner_rule.h"

#include "clrs.h"
#include "gtest/gtest.h"

Solution solution;

TEST(HornerRuleTest, HornerRule) {
  std::vector<int> nums = {1, 2, 3};
  ASSERT_EQ(solution.HornerRule(nums, 2), 17);
}

TEST(HornerRuleTest, NaivePolynomialEvaluation) {
  std::vector<int> nums = {1, 2, 3};
  ASSERT_EQ(solution.NaivePolynomialEvaluation(nums, 2), 17);
}
