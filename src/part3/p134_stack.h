#include "p134_singly_linked_list.h"

class Stack {
 public:
  deque<int> *q;

  Stack() { q = new deque<int>(); }

  bool Empty() { return q->empty(); }

  void Push(int key) { q->push_back(key); }

  tuple<int, error> Pop() {
    if (Empty()) {
      return {0, 1};
    }
    int ret = q->back();
    q->pop_back();
    return {ret, 0};
  }
};
