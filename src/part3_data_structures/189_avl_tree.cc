#include "clrs.h"

struct Node {
  int key;
  int height;
  Node* left;
  Node* right;

  explicit Node(int key) : key(key), height(0), left(nullptr), right(nullptr) {}
};

class AvlTree {
 public:
  AvlTree() { root_ = nullptr; }

  Node* root() { return root_; }

  bool IsAvlStructure() { return DfsHeight(root_) != -1; }

  Node* Insert(Node* node, int key) {
    if (node == nullptr) {
      return new Node(key);
    }
    if (key < node->key) {
      node->left = Insert(node->left, key);
    } else if (key > node->key) {
      node->right = Insert(node->right, key);
    } else {
      return node;
    }
    UpdateHeight(node);
    return BalanceInsert(node);
  }

  void Insert(int key) { root_ = Insert(root_, key); }

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
        Node* successor = Minimum(node->right);
        node->key = successor->key;
        node->right = Remove(node->right, successor->key);
      }
    }
    UpdateHeight(node);
    return BalanceDelete(node);
  }

 private:
  Node* root_;

  int DfsHeight(const Node* node) {
    if (node == nullptr) {
      return 0;
    }
    int left_height = DfsHeight(node->left);
    int right_height = DfsHeight(node->right);
    if (left_height == -1 || right_height == -1 || std::abs(left_height - right_height) > 1) {
      return -1;
    }
    return std::max(left_height, right_height) + 1;
  }

  Node* RightRotate(Node* p) {
    Node* l = p->left;
    p->left = l->right;
    l->right = p;
    UpdateHeight(p);
    UpdateHeight(l);
    return l;
  }

  Node* LeftRotate(Node* p) {
    Node* r = p->right;
    p->right = r->left;
    r->left = p;
    UpdateHeight(p);
    UpdateHeight(r);
    return r;
  }

  int GetHeight(const Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->height;
  }

  void UpdateHeight(Node* node) { node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1; }

  int BalanceFactor(const Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return GetHeight(node->left) - GetHeight(node->right);
  }

  Node* BalanceInsert(Node* node) {
    // if this node becomes unbalanced, then there are 4 cases

    // left left case
    if (BalanceFactor(node) == 2 && BalanceFactor(node->left) == 1) {
      return RightRotate(node);
    }

    // right right case
    if (BalanceFactor(node) == -2 && BalanceFactor(node->right) == -1) {
      return LeftRotate(node);
    }

    // left right case
    if (BalanceFactor(node) == 2 && BalanceFactor(node->left) == -1) {
      node->left = LeftRotate(node->left);
      return RightRotate(node);
    }

    // right left case
    if (BalanceFactor(node) == -2 && BalanceFactor(node->right) == 1) {
      node->right = RightRotate(node->right);
      return LeftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
  }

  Node* BalanceDelete(Node* node) {
    // if this node becomes unbalanced, then there are 4 cases

    // left left case
    if (BalanceFactor(node) == 2 && BalanceFactor(node->left) >= 0) {
      return RightRotate(node);
    }

    // right right case
    if (BalanceFactor(node) == -2 && BalanceFactor(node->right) <= 0) {
      return LeftRotate(node);
    }

    // left right case
    if (BalanceFactor(node) == 2 && BalanceFactor(node->left) == -1) {
      node->left = LeftRotate(node->left);
      return RightRotate(node);
    }

    // right left case
    if (BalanceFactor(node) == -2 && BalanceFactor(node->right) == 1) {
      node->right = RightRotate(node->right);
      return LeftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
  }

  Node* Minimum(Node* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  void PreorderTreeWalk(const Node* node) {
    if (node == nullptr) {
      return;
    }
    std::cout << node->key << " " << std::endl;
    PreorderTreeWalk(node->left);
    PreorderTreeWalk(node->right);
  }
};

int main() {
  AvlTree tree;
  std::vector<int> keys = {9, 5, 10, 0, 6, 11, -1, 1, 2};
  for (int key : keys) {
    tree.Insert(key);
  }
  std::cout << tree.IsAvlStructure() << std::endl;
  std::cout << tree.root() << std::endl;
}
