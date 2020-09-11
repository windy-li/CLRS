#include "p022_divided_sum.h"

void TestCanDivide() {
  vector<int> a = {8, 1, 4, 6, 9, 5};
  int x1 = 7;
  int x2 = 8;
  Solution s;
  cout << s.CanDivide(a, x1) << " " << s.CanDivide(a, x2);
}

int main() { TestCanDivide(); }
