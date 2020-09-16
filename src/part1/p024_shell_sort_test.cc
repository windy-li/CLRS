#include "p024_shell_sort.h"

void TestShellSort() {
  std::vector<int> a = {2, 3, 8, 6, 1};
  Solution s;
  s.ShellSort(a);
  clrs::PrintVector(a);
}

int main() { TestShellSort(); }
