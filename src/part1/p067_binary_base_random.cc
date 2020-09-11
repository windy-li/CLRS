#include "p067_binary_base_random.h"

int main() {
  int a = 4, b = 9;
  Solution s;
  for (int i = 0; i < 20; i++) {
    std::cout << s.BinaryBaseRandom(a, b) << " ";
  }
}
