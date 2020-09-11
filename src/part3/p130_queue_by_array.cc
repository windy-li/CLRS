#include "p130_queue_by_array.h"

int main() {
  Queue q(12);
  q.Push(15);
  q.Push(6);
  q.Push(9);
  q.Push(8);
  q.Push(4);
  std::cout << q.Pop();
}
