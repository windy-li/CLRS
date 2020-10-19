#include "p131_queue_by_two_stacks.h"

int main() {
  Queue q;
  q.Push(15);
  q.Push(6);
  q.Push(9);
  q.Push(8);
  q.Push(4);
  std::cout << q.Pop() << std::endl;
}

/*
 * 15
 */
