#include "part3_data_structures/129_stack_on_array.h"

TEST(StackOnArrayTest, Test1) {
  auto s = Stack(7);
  s.Push(15);
  s.Push(6);
  s.Push(2);
  s.Push(9);
  s.Push(17);
  s.Push(3);
  auto [ret, err] = s.Pop();
  if (!err) {
    std::cout << ret << std::endl;
  }
}
