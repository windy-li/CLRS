#include "p129_stack_by_array.h"

int main() {
  Stack s(7);
  s.Push(15);
  s.Push(6);
  s.Push(2);
  s.Push(9);
  s.Push(17);
  s.Push(3);
  auto [ret, err] = s.Pop();
  if (!err) {
    cout << ret;
  }
}
