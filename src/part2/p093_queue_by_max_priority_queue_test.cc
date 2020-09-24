#include "p093_queue_by_max_priority_queue.h"

int main() {
  int keys[] = {5, 2, 4, 6, 1, 3};
  int n = 6;
  Queue q(n);
  for (int i = 0; i < n; ++i) {
    q.Push(keys[i]);
  }
  for (int i = 0; i < n; ++i) {
    Node* node = q.Pop();
    std::cout << "{key: " << node->key << ", priority: " << node->priority << "}" << std::endl;
  }
}

/*
 * {key: 5, priority: 5}
 * {key: 2, priority: 4}
 * {key: 4, priority: 3}
 * {key: 6, priority: 2}
 * {key: 1, priority: 1}
 * {key: 3, priority: 0}
 */
