#include "clrs.h"

const bool kRed = true;
const bool kBlack = false;

struct Node {
  int key;
  Node* parent;
  Node* left;
  Node* right;
  bool color;

  Node(int key, bool color) : key(key), parent(nullptr), left(nullptr), right(nullptr), color(color) {}
};

class RedBlackTree {
 public:
  RedBlackTree() : nil_(new Node(-1, kBlack)), root_(nil_) {}

  Node* root() { return root_; }

  void InorderTreeWalk(Node* node) {
    if (node != nil_) {
      InorderTreeWalk(node->left);
      std::cout << node->key << std::endl;
      InorderTreeWalk(node->right);
    }
  }

  Node* Search(int key) {
    Node* node = root_;
    while (node != nil_ && node->key != key) {
      if (key < node->key) {
        node = node->left;
      } else {
        node = node->right;
      }
    }
    return node;
  }

  void Insert(int key) {
    Node* node = new Node(key, kRed);
    Node* p = nil_;
    Node* tmp = root_;
    while (tmp != nil_) {
      p = tmp;
      if (key < tmp->key) {
        tmp = tmp->left;
      } else {
        tmp = tmp->right;
      }
    }
    node->parent = p;
    if (p == nil_) {
      root_ = node;
    } else if (key < p->key) {
      p->left = node;
    } else {
      p->right = node;
    }
    node->left = nil_;
    node->right = nil_;
    InsertFixup(node);
  }

  void Remove(int key) {
    Node* node = Search(key);
    if (node == nil_) {
      return;
    }
    int deleted_color;
    Node* new_node;
    if (node->left == nil_) {
      deleted_color = node->color;
      new_node = node->right;
      Transplant(node->right, node);
    } else if (node->right == nil_) {
      deleted_color = node->color;
      new_node = node->left;
      Transplant(node->left, node);
    } else {
      Node* suc = Minimum(node->right);
      deleted_color = suc->color;
      new_node = suc->right;
      if (suc->parent != node) {
        Transplant(suc->right, suc);
        suc->right = node->right;
        suc->right->parent = suc;
      }
      Transplant(suc, node);
      suc->left = node->left;
      suc->left->parent = suc;
      suc->color = node->color;
    }
    if (deleted_color == kBlack) {
      RemoveFixup(new_node);
    }
  }

 private:
  Node* nil_;
  Node* root_;

  Node* Minimum(Node* node) {
    while (node->left != nil_) {
      node = node->left;
    }
    return node;
  }

  Node* Maximum(Node* node) {
    while (node->right != nil_) {
      node = node->right;
    }
    return node;
  }

  void Transplant(Node* source, Node* destination) {
    if (destination->parent == nil_) {
      root_ = source;
    } else if (destination == destination->parent->left) {
      destination->parent->left = source;
    } else {
      destination->parent->right = source;
    }
    source->parent = destination->parent;
  }

  void LeftRotate(Node* node) {
    Node* r = node->right;
    node->right = r->left;
    node->right->parent = node;
    r->parent = node->parent;
    if (node->parent == nil_) {
      root_ = r;
    } else if (node == node->parent->left) {
      node->parent->left = r;
    } else {
      node->parent->right = r;
    }
    r->left = node;
    r->left->parent = r;
  }

  void RightRotate(Node* node) {
    Node* l = node->left;
    node->left = l->right;
    node->left->parent = node;
    l->parent = node->parent;
    if (node->parent == nil_) {
      root_ = l;
    } else if (node == node->parent->right) {
      node->parent->right = l;
    } else {
      node->parent->left = l;
    }
    l->right = node;
    l->right->parent = l;
  }

  Node* Successor(Node* node) {
    if (node->right != nil_) {
      return Minimum(node->right);
    }
    Node* ancestor = node->parent;
    while (ancestor != nil_ && node == ancestor->right) {
      node = ancestor;
      ancestor = ancestor->parent;
    }
    return ancestor;
  }

  Node* Predecessor(Node* node) {
    if (node->left != nil_) {
      return Maximum(node->left);
    }
    Node* ancestor = node->parent;
    while (ancestor != nil_ && node == ancestor->left) {
      node = ancestor;
      ancestor = ancestor->parent;
    }
    return ancestor;
  }

  void InsertFixup(Node* node) {
    while (node->parent->color == kRed) {
      if (node->parent == node->parent->parent->left) {
        Node* uncle = node->parent->parent->right;
        if (uncle->color == kRed) {
          node->parent->color = kBlack;
          uncle->color = kBlack;
          node->parent->parent->color = kRed;
          node = node->parent->parent;
        } else {
          if (node == node->parent->right) {
            node = node->parent;
            LeftRotate(node);
          }
          node->parent->color = kBlack;
          node->parent->parent->color = kRed;
          RightRotate(node->parent->parent);
        }
      } else {
        Node* uncle = node->parent->parent->left;
        if (uncle->color == kRed) {
          node->parent->color = kBlack;
          uncle->color = kBlack;
          node->parent->parent->color = kRed;
          node = node->parent->parent;
        } else {
          if (node == node->parent->left) {
            node = node->parent;
            RightRotate(node);
          }
          node->parent->color = kBlack;
          node->parent->parent->color = kRed;
          LeftRotate(node->parent->parent);
        }
      }
    }
    root_->color = kBlack;
  }

  void RemoveFixup(Node* node) {
    while (node != nil_ && node->color == kBlack) {
      if (node == node->parent->left) {
        Node* sibling = node->parent->right;
        if (sibling->color == kRed) {
          sibling->color = kBlack;
          node->parent->color = kRed;
          LeftRotate(node->parent);
          sibling = node->parent->right;
        }
        if (sibling->left->color == kBlack && sibling->right->color == kBlack) {
          sibling->color = kRed;
          node = node->parent;
        } else {
          if (sibling->right->color == kBlack) {
            sibling->left->color = kBlack;
            sibling->color = kRed;
            RightRotate(sibling);
            sibling = node->parent->right;
          }
          sibling->right->color = kBlack;
          sibling->color = node->parent->color;
          node->parent->color = kBlack;
          LeftRotate(node->parent);
          node = root_;
        }
      } else {
        Node* sibling = node->parent->left;
        if (sibling->color == kRed) {
          sibling->color = kBlack;
          node->parent->color = kRed;
          RightRotate(node->parent);
          sibling = node->parent->left;
        }
        if (sibling->left->color == kBlack && sibling->right->color == kBlack) {
          sibling->color = kRed;
          node = node->parent;
        } else {
          if (sibling->left->color == kBlack) {
            sibling->right->color = kBlack;
            sibling->color = kRed;
            LeftRotate(sibling);
            sibling = node->parent->left;
          }
          sibling->left->color = kBlack;
          sibling->color = node->parent->color;
          node->parent->color = kBlack;
          RightRotate(node->parent);
          node = root_;
        }
      }
    }
    node->color = kBlack;
  }
};

void TestRedBlackTree() {
  RedBlackTree tree;
  std::vector<int> keys = {11, 2, 14, 1, 7, 15, 5, 8};
  for (int key : keys) {
    tree.Insert(key);
  }
  std::cout << tree.root()->key << std::endl;
}

int main() { TestRedBlackTree(); }

/*
 * {key: 11, color: BLACK, parent: -1, left: 2, right: 14}
 */
