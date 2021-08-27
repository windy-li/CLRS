#include "part1_foundations/023_horner_rule.h"

Solution solution;

TEST(HornerRuleTest, HornerRule) {
  auto nums = std::vector<int>{1, 2, 3};
  ASSERT_EQ(solution.HornerRule(nums, 2), 17);
}

TEST(HornerRuleTest, NaivePolynomialEvaluation) {
  auto nums = std::vector<int>{1, 2, 3};
  ASSERT_EQ(solution.NaivePolynomialEvaluation(nums, 2), 17);
}

RUN_TESTS()
