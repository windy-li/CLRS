#include "clrs.h"

const int kRed = 1;
const int kBlack = 0;

struct Node {
  int key;
  Node *parent;
  Node *left;
  Node *right;
  int color;

  Node(int key, int color)
      : key(key), parent(nullptr), left(nullptr), right(nullptr), color(color) {}
};

class RedBlackTree {
 public:
  RedBlackTree() : nil_(new Node(-1, kBlack)), root_(nil_) {}

  Node *root() { return root_; }

  void InorderTreeWalk(Node *x) {
    if (x != nil_) {
      InorderTreeWalk(x->left);
      std::cout << x->key << std::endl;
      InorderTreeWalk(x->right);
    }
  }

  Node *Search(int k) {
    Node *x = root_;
    while (x != nil_ && x->key != k) {
      if (k < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    return x;
  }

  void Insert(int k) {
    Node *x = new Node(k, kRed);
    Node *p = nil_;
    Node *tmp = root_;
    while (tmp != nil_) {
      p = tmp;
      if (k < tmp->key) {
        tmp = tmp->left;
      } else {
        tmp = tmp->right;
      }
    }
    x->parent = p;
    if (p == nil_) {
      root_ = x;
    } else if (k < p->key) {
      p->left = x;
    } else {
      p->right = x;
    }
    x->left = nil_;
    x->right = nil_;
    InsertFixup(x);
  }

  void Remove(int k) {
    Node *x = Search(k);
    if (x == nil_) {
      return;
    }
    int c;
    Node *r;
    if (x->left == nil_) {
      c = x->color;
      r = x->right;
      Transplant(x->right, x);
    } else if (x->right == nil_) {
      c = x->color;
      r = x->left;
      Transplant(x->left, x);
    } else {
      Node *suc = Minimum(x->right);
      c = suc->color;
      r = suc->right;
      if (suc->parent != x) {
        Transplant(suc->right, suc);
        suc->right = x->right;
        suc->right->parent = suc;
      }
      Transplant(suc, x);
      suc->left = x->left;
      suc->left->parent = suc;
      suc->color = x->color;
    }
    if (c == kBlack) {
      RemoveFixup(r);
    }
  }

 private:
  Node *nil_;
  Node *root_;

  Node *Minimum(Node *x) {
    while (x->left != nil_) {
      x = x->left;
    }
    return x;
  }

  Node *Maximum(Node *x) {
    while (x->right != nil_) {
      x = x->right;
    }
    return x;
  }

  void Transplant(Node *src, Node *dst) {
    if (dst->parent == nil_) {
      root_ = src;
    } else if (dst == dst->parent->left) {
      dst->parent->left = src;
    } else {
      dst->parent->right = src;
    }
    src->parent = dst->parent;
  }

  void LeftRotate(Node *x) {
    Node *r = x->right;
    x->right = r->left;
    x->right->parent = x;
    r->parent = x->parent;
    if (x->parent == nil_) {
      root_ = r;
    } else if (x == x->parent->left) {
      x->parent->left = r;
    } else {
      x->parent->right = r;
    }
    r->left = x;
    r->left->parent = r;
  }

  void RightRotate(Node *x) {
    Node *l = x->left;
    x->left = l->right;
    x->left->parent = x;
    l->parent = x->parent;
    if (x->parent == nil_) {
      root_ = l;
    } else if (x == x->parent->right) {
      x->parent->right = l;
    } else {
      x->parent->left = l;
    }
    l->right = x;
    l->right->parent = l;
  }

  Node *Successor(Node *x) {
    if (x->right != nil_) {
      return Minimum(x->right);
    }
    Node *ancestor = x->parent;
    while (ancestor != nil_ && x == ancestor->right) {
      x = ancestor;
      ancestor = ancestor->parent;
    }
    return ancestor;
  }

  Node *Predecessor(Node *x) {
    if (x->left != nil_) {
      return Maximum(x->left);
    }
    Node *ancestor = x->parent;
    while (ancestor != nil_ && x == ancestor->left) {
      x = ancestor;
      ancestor = ancestor->parent;
    }
    return ancestor;
  }

  void InsertFixup(Node *x) {
    while (x->parent->color == kRed) {
      if (x->parent == x->parent->parent->left) {
        Node *uncle = x->parent->parent->right;
        if (uncle->color == kRed) {
          x->parent->color = kBlack;
          uncle->color = kBlack;
          x->parent->parent->color = kRed;
          x = x->parent->parent;
        } else {
          if (x == x->parent->right) {
            x = x->parent;
            LeftRotate(x);
          }
          x->parent->color = kBlack;
          x->parent->parent->color = kRed;
          RightRotate(x->parent->parent);
        }
      } else {
        Node *uncle = x->parent->parent->left;
        if (uncle->color == kRed) {
          x->parent->color = kBlack;
          uncle->color = kBlack;
          x->parent->parent->color = kRed;
          x = x->parent->parent;
        } else {
          if (x == x->parent->left) {
            x = x->parent;
            RightRotate(x);
          }
          x->parent->color = kBlack;
          x->parent->parent->color = kRed;
          LeftRotate(x->parent->parent);
        }
      }
    }
    root_->color = kBlack;
  }

  void RemoveFixup(Node *x) {
    while (x != nil_ && x->color == kBlack) {
      if (x == x->parent->left) {
        Node *sibling = x->parent->right;
        if (sibling->color == kRed) {
          sibling->color = kBlack;
          x->parent->color = kRed;
          LeftRotate(x->parent);
          sibling = x->parent->right;
        }
        if (sibling->left->color == kBlack && sibling->right->color == kBlack) {
          sibling->color = kRed;
          x = x->parent;
        } else {
          if (sibling->right->color == kBlack) {
            sibling->left->color = kBlack;
            sibling->color = kRed;
            RightRotate(sibling);
            sibling = x->parent->right;
          }
          sibling->right->color = kBlack;
          sibling->color = x->parent->color;
          x->parent->color = kBlack;
          LeftRotate(x->parent);
          x = root_;
        }
      } else {
        Node *sibling = x->parent->left;
        if (sibling->color == kRed) {
          sibling->color = kBlack;
          x->parent->color = kRed;
          RightRotate(x->parent);
          sibling = x->parent->left;
        }
        if (sibling->left->color == kBlack && sibling->right->color == kBlack) {
          sibling->color = kRed;
          x = x->parent;
        } else {
          if (sibling->left->color == kBlack) {
            sibling->right->color = kBlack;
            sibling->color = kRed;
            LeftRotate(sibling);
            sibling = x->parent->left;
          }
          sibling->left->color = kBlack;
          sibling->color = x->parent->color;
          x->parent->color = kBlack;
          RightRotate(x->parent);
          x = root_;
        }
      }
    }
    x->color = kBlack;
  }
};
