#include "clrs.h"

struct Node {
  int key;
  Node* parent;
  Node* left;
  Node* right;

  explicit Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
 public:
  BinarySearchTree() : root_(nullptr) {}

  Node* root() { return root_; }

  void InorderTreeWalk(Node* node) {
    if (node != nullptr) {
      InorderTreeWalk(node->left);
      std::cout << node->key << " ";
      InorderTreeWalk(node->right);
    }
  }

  void MorrisTraversal(Node* node) {
    while (node != nullptr) {
      if (node->left == nullptr) {
        std::cout << node << std::endl;
        node = node->right;
      } else {
        // Find the inorder predecessor of current
        Node* pre = node->left;
        while (pre->right != nullptr && pre->right != node) {
          pre = pre->right;
        }
        // Make current as right child of its inorder predecessor
        if (pre->right == nullptr) {
          pre->right = node;
          node = node->left;
        } else {
          // Revert the changes made in "if" part to restore the original tree,
          // fix the right child of predecessor
          pre->right = nullptr;
          std::cout << node << std::endl;
          node = node->right;
        }
      }
    }
  }

  Node* Search(int key) {
    Node* node = root_;
    while (node != nullptr && node->key != key) {
      if (key < node->key) {
        node = node->left;
      } else {
        node = node->right;
      }
    }
    return node;
  }

  void Insert(int key) {
    Node* node = new Node(key);
    Node* p = nullptr;
    Node* temp = root_;
    while (temp != nullptr) {
      p = temp;
      if (key < temp->key) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }
    node->parent = p;
    if (p == nullptr) {
      root_ = node;
    } else if (key < p->key) {
      p->left = node;
    } else {
      p->right = node;
    }
  }

  void Remove(int key) {
    Node* node = Search(key);
    if (node == nullptr) {
      return;
    }
    if (node->left == nullptr) {
      Transplant(node->right, node);
    } else if (node->right == nullptr) {
      Transplant(node->left, node);
    } else {
      Node* suc = Minimum(node->right);
      if (suc->parent != node) {
        Transplant(suc->right, suc);
        suc->right = node->right;
        suc->right->parent = suc;
      }
      Transplant(suc, node);
      suc->left = node->left;
      suc->left->parent = suc;
    }
  }

 private:
  Node* root_;

  Node* Minimum(Node* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  Node* Maximum(Node* node) {
    while (node->right != nullptr) {
      node = node->right;
    }
    return node;
  }

  Node* Successor(Node* node) {
    if (node->right != nullptr) {
      return Minimum(node->right);
    }
    Node* p = node->parent;
    while (p != nullptr && node == p->right) {
      node = p;
      p = p->parent;
    }
    return p;
  }

  Node* Predecessor(Node* node) {
    if (node->left != nullptr) {
      return Maximum(node->left);
    }
    Node* p = node->parent;
    while (p != nullptr && node == p->left) {
      node = p;
      p = p->parent;
    }
    return p;
  }

  void Transplant(Node* src, Node* dst) {
    if (dst->parent == nullptr) {
      root_ = src;
    } else if (dst == dst->parent->left) {
      dst->parent->left = src;
    } else {
      dst->parent->right = src;
    }
    if (src != nullptr) {
      src->parent = dst->parent;
    }
  }
};
