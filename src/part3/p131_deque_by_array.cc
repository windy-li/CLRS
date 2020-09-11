#include "p131_deque_by_array.h"

void TestDeque() {
  Deque q(5);
  q.PushBack(5);
  q.PushBack(10);
  std::cout << q.PopBack() << std::endl;
  q.PushFront(15);
  std::cout << q.PopFront() << std::endl;
  std::cout << q.PopFront() << std::endl;
}

int main() { TestDeque(); }

// 10
// 15
// 5
