#include "p023_horner_rule.h"

int main() {
  vector<int> a = {1, 2, 3};
  int x = 2;
  Solution s;
  cout << s.HornerRule(a, x) << " " << s.NaivePolynomialEvaluation(a, x);
}
