#include "clrs.h"

struct Node {
  int key;
  Node* parent;
  Node* left;
  Node* right;
  Node* child;
  int degree;
  bool mark;

  explicit Node(int key)
      : key(key), parent(nullptr), left(nullptr), right(nullptr), child(nullptr), degree(0), mark(false) {}

  static std::string ToString(Node* node) {
    if (node == nullptr) {
      return "nullptr";
    }
    std::string parent_str = node->parent == nullptr ? "" : ", parent=" + std::to_string(node->parent->key);
    std::string left_str = node->left == nullptr ? "" : ", left=" + std::to_string(node->left->key);
    std::string right_str = node->right == nullptr ? "" : ", right=" + std::to_string(node->right->key);
    std::string child_str = node->child == nullptr ? "" : ", child=" + std::to_string(node->child->key);
    std::string str;
    return str + "Node{" + "key=" + std::to_string(node->key) + parent_str + left_str + right_str + child_str +
           ", degree=" + std::to_string(node->degree) + ",mark=" + std::to_string(node->mark) + "}";
  }

  friend std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << Node::ToString(const_cast<Node*>(&node));
    return os;
  }
};

class FibHeap {
 public:
  FibHeap() : min_(nullptr), n_(0) {}

  void Insert(int key) {
    Node* new_node = new Node(key);
    if (min_ == nullptr) {
      CreateCycle(new_node);
      min_ = new_node;
    } else {
      InsertIntoCycle(new_node, min_);
      if (new_node->key < min_->key) {
        min_ = new_node;
      }
    }
    n_++;
  }

  FibHeap* Union(FibHeap* heap1, FibHeap* heap2) {
    auto* newHeap = new FibHeap();
    newHeap->min_ = heap1->min_;
    newHeap->n_ = heap1->n_ + heap2->n_;
    ConcatenateCycle(heap1->min_, heap2->min_);
    if (heap1->min_ == nullptr || (heap2->min_ != nullptr && heap2->min_->key < heap1->min_->key)) {
      newHeap->min_ = heap2->min_;
    }
    return newHeap;
  }

  Node* ExtractMin() {
    Node* z = min_;
    if (z != nullptr) {
      Node* c = z->child;
      if (c != nullptr) {
        do {
          Node* temp = c;
          c = c->right;
          InsertIntoCycle(temp, min_);
          temp->parent = nullptr;
        } while (c->right != z->child);
      }
      RemoveFromCycle(z);
      if (z == z->right) {
        min_ = nullptr;
      } else {
        min_ = z->right;
        Consolidate();
      }
      n_--;
    }
    return z;
  }

  void DecreaseKey(Node* node, int newKey) {
    if (newKey > node->key) {
      throw std::invalid_argument("new key is greater than current key");
    }
    node->key = newKey;
    Node* p = node->parent;
    if (p != nullptr && node->key < p->key) {
      Cut(node, p);
      CascadingCut(p);
    }
    if (node->key < min_->key) {
      min_ = node;
    }
  }

  Node* Minimum() { return min_; }

 private:
  Node* min_;
  int n_;

  void CreateCycle(Node* node) {
    node->left = node;
    node->right = node;
  }

  void InsertIntoCycle(Node* new_node, Node* target) {
    target->left->right = new_node;
    new_node->left = target->left;
    target->left = new_node;
    new_node->right = target;
  }

  void ConcatenateCycle(Node* x, Node* y) {
    if (x == nullptr || y == nullptr) {
      return;
    }
    x->right->left = y->left;
    y->left->right = x->right;
    x->right = y;
    y->left = x;
  }

  void RemoveFromCycle(Node* node) {
    node->left->right = node->right;
    node->right->left = node->left;
  }

  void Consolidate() {
    std::vector<Node*> a(D() + 1, nullptr);
    for (int i = 0; i <= D(); i++) {
      a[i] = nullptr;
    }
    Node* w = min_;
    do {
      Node* x = w;
      w = w->right;
      int d = x->degree;
      while (a[d] != nullptr) {
        Node* y = a[d];
        if (x->key > y->key) {
          Node* temp = x;
          x = y;
          y = temp;
        }
        Link(y, x);
        a[d] = nullptr;
        d++;
      }
      a[d] = x;
    } while (w != min_);
    min_ = nullptr;
    for (int i = 0; i <= D(); i++) {
      if (a[i] != nullptr) {
        if (min_ == nullptr) {
          CreateCycle(a[i]);
          min_ = a[i];
        } else {
          InsertIntoCycle(a[i], min_);
          if (a[i]->key < min_->key) {
            min_ = a[i];
          }
        }
      }
    }
  }

  int D() { return (int)(std::log((double)n_) / std::log(1.618)) + 1; }

  void Link(Node* c, Node* p) {
    RemoveFromCycle(c);
    if (p->child == nullptr) {
      p->child = c;
      CreateCycle(c);
    } else {
      InsertIntoCycle(c, p->child);
    }
    p->degree++;
    c->mark = false;
  }

  void Cut(Node* c, Node* p) {
    RemoveFromCycle(c);
    p->degree++;
    InsertIntoCycle(c, min_);
    c->parent = nullptr;
    c->mark = false;
  }

  void CascadingCut(Node* c) {
    Node* p = c->parent;
    if (p != nullptr) {
      if (!c->mark) {
        c->mark = true;
      } else {
        Cut(c, p);
        CascadingCut(p);
      }
    }
  }
};

FibHeap* TestFibHeap1() {
  auto* heap = new FibHeap();
  heap->Insert(7);
  heap->Insert(5);
  heap->Insert(8);
  std::cout << Node::ToString(heap->Minimum()) << std::endl;
  std::cout << Node::ToString(heap->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap->ExtractMin()) << std::endl;
  return heap;
}

FibHeap* TestFibHeap2() {
  auto* heap = new FibHeap();
  heap->Insert(10);
  heap->Insert(11);
  heap->Insert(9);
  std::cout << Node::ToString(heap->Minimum()) << std::endl;
  std::cout << Node::ToString(heap->ExtractMin()) << std::endl;
  return heap;
}

void TestFibHeap3(FibHeap* heap1, FibHeap* heap2) {
  FibHeap* heap3 = heap1->Union(heap1, heap2);
  std::cout << Node::ToString(heap3->Minimum()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
  std::cout << Node::ToString(heap3->ExtractMin()) << std::endl;
}

int main() {
  FibHeap* heap1 = TestFibHeap1();
  clrs::PrintBorder();
  FibHeap* heap2 = TestFibHeap2();
  clrs::PrintBorder();
  TestFibHeap3(heap1, heap2);
}
