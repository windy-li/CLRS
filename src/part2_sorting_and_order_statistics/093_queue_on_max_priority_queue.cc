#include "clrs.h"

struct Node {
  int key;
  int priority;

  Node(int key, int priority) : key(key), priority(priority) {}

  Node() : key(0), priority(0) {}
};

class Queue {
 public:
  explicit Queue(int capacity) : nodes_(std::vector<Node*>(capacity, nullptr)), count_(capacity), heap_size_(0) {}

  void Push(int key) {
    Node* node = new Node(key, INT_MIN);
    heap_size_++;
    count_--;
    nodes_[heap_size_ - 1] = node;
    IncreasePriority(heap_size_ - 1, count_);
  }

  Node* Pop() {
    if (heap_size_ < 1) {
      throw std::runtime_error("Heap underflow");
    }
    Node* head = nodes_[0];
    nodes_[0] = nodes_[heap_size_ - 1];
    heap_size_--;
    MaxHeapify(0);
    return head;
  }

 private:
  std::vector<Node*> nodes_;
  int count_;
  int heap_size_;

  void MaxHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if (l < heap_size_ && nodes_[l]->priority > nodes_[largest]->priority) {
      largest = l;
    }
    if (r < heap_size_ && nodes_[r]->priority > nodes_[largest]->priority) {
      largest = r;
    }
    if (largest != i) {
      std::swap(nodes_[largest], nodes_[i]);
      MaxHeapify(largest);
    }
  }

  void IncreasePriority(int i, int priority) {
    if (priority < nodes_[i]->priority) {
      throw std::runtime_error("new priority is lower than current priority");
    }
    nodes_[i]->priority = priority;
    Node* node = nodes_[i];
    while (i > 0 && nodes_[Parent(i)]->priority < priority) {
      nodes_[i] = nodes_[Parent(i)];
      i = Parent(i);
    }
    nodes_[i] = node;
  }

  int Left(int i) { return 2 * i + 1; }

  int Right(int i) { return 2 * i + 2; }

  int Parent(int i) { return (i - 1) / 2; }
};

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
