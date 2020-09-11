#include "clrs.h"

class Solution {
 public:
  vector<int> ComplexNumberMultiply(int a, int b, int c, int d) {
    int p1 = (a + b) * c;
    int p2 = b * (c + d);
    int p3 = (a - b) * d;
    return vector<int>{p1 - p2, p2 + p3};
  }
};
