#include "p131_deque_by_array.h"

void TestDeque() {
  Deque q(5);
  q.PushBack(5);
  q.PushBack(10);
  cout << q.PopBack() << endl;
  q.PushFront(15);
  cout << q.PopFront() << endl;
  cout << q.PopFront() << endl;
}

int main() { TestDeque(); }

// 10
// 15
// 5
