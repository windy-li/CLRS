#include "clrs.h"

struct Node {
  int key;
  int priority;
  Node* left;
  Node* right;

  explicit Node(int key) : key(key), priority(clrs::RandomInt(0, 100)), left(nullptr), right(nullptr) {}
};

class Treap {
 public:
  Treap() { root_ = nullptr; }

  Node* root() { return root_; }

  Node* RightRotate(Node* p) {
    Node* l = p->left;
    p->left = l->right;
    l->right = p;
    return l;
  }

  Node* LeftRotate(Node* p) {
    Node* r = p->right;
    p->right = r->left;
    r->left = p;
    return r;
  }

  Node* Search(int key) { return Search(root_, key); }

  Node* Search(Node* node, int key) {
    if (node == nullptr || key == node->key) {
      return node;
    }
    if (key < node->key) {
      return Search(node->left, key);
    } else {
      return Search(node->right, key);
    }
  }

  void Insert(int key) { root_ = Insert(root_, key); }

  Node* Insert(Node* node, int key) {
    if (node == nullptr) {
      return new Node(key);
    }
    if (key < node->key) {
      node->left = Insert(node->left, key);
      if (node->left->priority < node->priority) {
        node = RightRotate(node);
      }
    } else if (key > node->key) {
      node->right = Insert(node->right, key);
      if (node->right->priority < node->priority) {
        node = LeftRotate(node);
      }
    }
    return node;
  }

  void Remove(int key) { root_ = Remove(root_, key); }

  Node* Remove(Node* node, int key) {
    if (node == nullptr) {
      return nullptr;
    }
    if (key < node->key) {
      node->left = Remove(node->left, key);
    } else if (key > node->key) {
      node->right = Remove(node->right, key);
    } else {
      if (node->left == nullptr) {
        node = node->right;
      } else if (node->right == nullptr) {
        node = node->left;
      } else {
        if (node->left->priority < node->right->priority) {
          node = RightRotate(node);
          node->right = Remove(node->right, key);
        } else {
          node = LeftRotate(node);
          node->left = Remove(node->left, key);
        }
      }
    }
    return node;
  }

  void Inorder(Node* node) {
    if (node != nullptr) {
      Inorder(node->left);
      std::cout << node << std::endl;
      Inorder(node->right);
    }
  }

 private:
  Node* root_;
};

int main() {
  Treap t;
  int keys[] = {5, 3, 2, 4, 7, 6, 1, 8};
  for (int key : keys) {
    t.Insert(key);
  }
  t.Inorder(t.root());
  std::cout << t.Search(3) << std::endl;
  t.Remove(3);
  std::cout << t.Search(3) << std::endl;
}
