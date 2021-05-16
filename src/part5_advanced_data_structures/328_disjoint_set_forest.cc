#include "clrs.h"

struct Node {
  int key;
  Node* parent;
  int rank;

  explicit Node(int key) : key(key), parent(nullptr), rank(0) {}

  static std::string ToString(Node* node) { return std::to_string(node->key); }
};

class DisjointSetForest {
 public:
  Node* MakeSet(int key) {
    Node* node = new Node(key);
    node->parent = node;
    return node;
  }

  void Union(Node* x, Node* y) { Link(FindSet(x), FindSet(y)); }

  void PrintSets(std::vector<Node*>& nodes) {
    for (int i = 1; i < nodes.size(); i++) {
      std::string str;
      Node* node = nodes[i];
      str += std::to_string(node->key);
      while (node != node->parent) {
        str += " " + std::to_string(node->parent->key);
        node = node->parent;
      }
      std::cout << str << std::endl;
    }
  }

  Node* FindSet(Node* node) {
    if (node != node->parent) {
      node->parent = FindSet(node->parent);
    }
    return node->parent;
  }

 private:
  void Link(Node* x, Node* y) {
    if (x->rank > y->rank) {
      y->parent = x;
    } else {
      x->parent = y;
      if (x->rank == y->rank) {
        y->rank++;
      }
    }
  }
};

void TestDisjointSetForest() {
  DisjointSetForest self;

  std::vector<Node*> nodes(17, nullptr);
  for (int i = 1; i <= 16; i++) {
    nodes[i] = self.MakeSet(i);
  }
  for (int i = 1; i <= 15; i += 2) {
    self.Union(nodes[i], nodes[i + 1]);
  }

  self.PrintSets(nodes);
  clrs::PrintBorder();

  // in this line, we now have:
  // {1, 2, 3, 4} {5, 6, 7, 8} {9, 10, 11, 12} {13, 14, 15, 16}

  self.Union(nodes[1], nodes[5]);
  self.Union(nodes[11], nodes[13]);
  self.Union(nodes[1], nodes[10]);

  self.PrintSets(nodes);
  clrs::PrintBorder();

  std::cout << Node::ToString(self.FindSet(nodes[2])) << std::endl;
  std::cout << Node::ToString(self.FindSet(nodes[9])) << std::endl;
}

int main() { TestDisjointSetForest(); }

/*
1 2
2
3 4
4
5 6
6
7 8
8
9 10
10
11 12
12
13 14
14
15 16
16
------------------------------
1 2 4
2 4
3 4
4
5 6 8
6 8
7 8
8
9 10 12
10 12
11 12
12
13 14 16
14 16
15 16
16
------------------------------
1 8 16
2 4 8 16
3 4 8 16
4 8 16
5 8 16
6 8 16
7 8 16
8 16
9 10 16
10 16
11 12 16
12 16
13 16
14 16
15 16
16
------------------------------
16
16
 */
