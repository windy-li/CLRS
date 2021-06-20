#include <algorithm>
#include <limits>
#include <vector>

struct Node {
  int key;
  int array_id;

  Node(int key, int array_id) : key(key), array_id(array_id) {}
};

class MinHeap {
 public:
  explicit MinHeap(int capacity) : nodes_(std::vector<Node*>(capacity, nullptr)), heap_size_(0) {}

  void Insert(int key, int array_id) {
    heap_size_++;
    nodes_[heap_size_ - 1] = new Node(std::numeric_limits<int>::max(), array_id);
    DecreaseKey(heap_size_ - 1, key);
  }

  bool Empty() { return heap_size_ == 0; }

  Node* ExtractMin() {
    if (Empty()) {
      throw std::underflow_error("Heap underflow");
    }
    Node* head = nodes_[0];
    nodes_[0] = nodes_[heap_size_ - 1];
    heap_size_--;
    MinHeapify(0);
    return head;
  }

 private:
  std::vector<Node*> nodes_;
  int heap_size_;

  void DecreaseKey(int i, int new_key) {
    if (new_key > nodes_[i]->key) {
      throw std::invalid_argument("new key is lower than current key");
    }
    nodes_[i]->key = new_key;
    Node* temp = nodes_[i];
    while (i > 0 && nodes_[Parent(i)]->key > new_key) {
      nodes_[i] = nodes_[Parent(i)];
      i = Parent(i);
    }
    nodes_[i] = temp;
  }

  void MinHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int least = i;
    if (l < heap_size_ && nodes_[l]->key < nodes_[least]->key) {
      least = l;
    }
    if (r < heap_size_ && nodes_[r]->key < nodes_[least]->key) {
      least = r;
    }
    if (least != i) {
      std::swap(nodes_[least], nodes_[i]);
      MinHeapify(least);
    }
  }

  int Left(int i) { return 2 * i + 1; }

  int Right(int i) { return 2 * i + 2; }

  int Parent(int i) { return (i - 1) / 2; }
};
