#include "p134_stack.h"

int main() {
  auto *self = new Stack();
  self->Push(15);
  self->Push(6);
  self->Push(2);
  self->Push(9);
  self->Push(17);
  self->Push(3);
  std::cout << self->Pop() << std::endl;
  return 0;
}

/*
 * 3
 */
