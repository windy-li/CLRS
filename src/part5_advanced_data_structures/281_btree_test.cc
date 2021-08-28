#include "clrs.h"

struct Node {
  int n;
  bool leaf;
  std::vector<int> keys;
  std::vector<Node*> children;

  explicit Node(int t)
      : n(0), leaf(false), keys(std::vector<int>(2 * t - 1)), children(std::vector<Node*>(2 * t, nullptr)) {}
};

class BTree {
 public:
  explicit BTree(int minimum_degree) : t_(minimum_degree), root_(new Node(minimum_degree)) {
    root_->n = 0;
    root_->leaf = true;
  }

  std::tuple<Node*, int> Search(Node* node, int key) {
    int i = 0;
    while (i < node->n && key > node->keys[i]) {
      i++;
    }
    if (i < node->n && key == node->keys[i]) {
      return {node, i};
    } else {
      if (node->leaf) {
        return {nullptr, 0};
      } else {
        return Search(node->children[i], key);
      }
    }
  }

  void Insert(int key) {
    Node* r = root_;
    if (r->n == 2 * t_ - 1) {
      auto node = new Node(t_);
      root_ = node;
      node->leaf = false;
      node->n = 0;
      node->children[0] = r;
      SplitChild(node, 0);
      InsertNonFull(node, key);
    } else {
      InsertNonFull(r, key);
    }
  }

 private:
  Node* root_;
  int t_;

  void SplitChild(Node* x, int i) {
    Node* y = x->children[i];
    auto z = new Node(t_);
    z->leaf = y->leaf;
    z->n = t_ - 1;
    y->n = t_ - 1;
    for (int j = 0; j < t_ - 1; ++j) {
      z->keys[j] = y->keys[t_ + j];
    }
    if (!y->leaf) {
      for (int j = 0; j < t_; ++j) {
        z->children[j] = y->children[t_ + j];
      }
    }
    for (int j = x->n; j >= i + 1; --j) {
      x->children[j + 1] = x->children[j];
    }
    x->children[i + 1] = z;
    for (int j = x->n - 1; j >= i; --j) {
      x->keys[j + 1] = x->keys[j];
    }
    x->keys[i] = y->keys[t_ - 1];
    x->n++;
  }

  void InsertNonFull(Node* node, int key) {
    int i = node->n - 1;
    if (node->leaf) {
      while (i >= 0 && i < node->n && key < node->keys[i]) {
        node->keys[i + 1] = node->keys[i];
        i--;
      }
      node->keys[i + 1] = key;
      node->n++;
    } else {
      while (i >= 0 && i < node->n && key < node->keys[i]) {
        i--;
      }
      i++;
      if (node->children[i]->n == 2 * t_ - 1) {
        SplitChild(node, i);
        if (key > node->keys[i]) {
          i++;
        }
      }
      InsertNonFull(node->children[i], key);
    }
  }
};
