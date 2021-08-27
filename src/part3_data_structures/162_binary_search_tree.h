#ifndef CLRS_SRC_PART3_DATA_STRUCTURES_162_BINARY_SEARCH_TREE_H_
#define CLRS_SRC_PART3_DATA_STRUCTURES_162_BINARY_SEARCH_TREE_H_

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

  void InorderTreeWalk(const Node* node) {
    if (node == nullptr) {
      return;
    }
    InorderTreeWalk(node->left);
    std::cout << node->key << " ";
    InorderTreeWalk(node->right);
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
    Node* temp_parent = nullptr;
    Node* temp = root_;
    while (temp != nullptr) {
      temp_parent = temp;
      if (key < temp->key) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }
    node->parent = temp_parent;
    if (temp_parent == nullptr) {
      root_ = node;
    } else if (key < temp_parent->key) {
      temp_parent->left = node;
    } else {
      temp_parent->right = node;
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
      Node* successor = Minimum(node->right);
      if (successor->parent != node) {
        Transplant(successor->right, successor);
        successor->right = node->right;
        successor->right->parent = successor;
      }
      Transplant(successor, node);
      successor->left = node->left;
      successor->left->parent = successor;
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

  void Transplant(Node* source, Node* destination) {
    if (destination->parent == nullptr) {
      root_ = source;
    } else if (destination == destination->parent->left) {
      destination->parent->left = source;
    } else {
      destination->parent->right = source;
    }
    if (source != nullptr) {
      source->parent = destination->parent;
    }
  }
};

#endif  // CLRS_SRC_PART3_DATA_STRUCTURES_162_BINARY_SEARCH_TREE_H_
