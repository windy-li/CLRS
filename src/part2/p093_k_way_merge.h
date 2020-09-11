#include "clrs.h"

struct Node {
  int key;
  int array_id;

  Node(int key, int array_id) : key(key), array_id(array_id) {}
};

class MinHeap {
 public:
  explicit MinHeap(int capacity) : nodes(std::vector<Node*>(capacity, nullptr)), heap_size(0) {}

  void Insert(int key, int arrayId) {
    heap_size++;
    nodes[heap_size - 1] = new Node(INT_MAX, arrayId);
    DecreaseKey(heap_size - 1, key);
  }

  bool Empty() { return heap_size == 0; }

  Node* ExtractMin() {
    if (Empty()) {
      throw std::underflow_error("Heap underflow");
    }
    Node* head = nodes[0];
    nodes[0] = nodes[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return head;
  }

 private:
  std::vector<Node*> nodes;
  int heap_size;

  void DecreaseKey(int i, int new_key) {
    if (new_key > nodes[i]->key) {
      std::cerr << "new key is lower than current key" << std::endl;
    }
    nodes[i]->key = new_key;
    Node* temp = nodes[i];
    while (i > 0 && nodes[Parent(i)]->key > new_key) {
      nodes[i] = nodes[Parent(i)];
      i = Parent(i);
    }
    nodes[i] = temp;
  }

  void MinHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int least = i;
    if (l < heap_size && nodes[l]->key < nodes[least]->key) {
      least = l;
    }
    if (r < heap_size && nodes[r]->key < nodes[least]->key) {
      least = r;
    }
    if (least != i) {
      std::swap(nodes[least], nodes[i]);
      MinHeapify(least);
    }
  }

  int Left(int i) { return 2 * i + 1; }

  int Right(int i) { return 2 * i + 2; }

  int Parent(int i) { return (i - 1) / 2; }
};
