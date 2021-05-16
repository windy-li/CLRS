#include "clrs.h"

struct Node;
struct Set;

struct Node {
  int key;
  Node* next;
  Set* set;

  explicit Node(int key) : key(key), next(nullptr), set(nullptr) {}
};

struct Set {
  Node* head;
  Node* tail;
  int weight;

  Set() : tail(nullptr), head(nullptr), weight(0) {}

  static std::string ToString(Set* set) {
    std::string str;
    Node* node = set->head;
    str += "{";
    while (node != nullptr) {
      str += std::to_string(node->key);
      node = node->next;
      if (node != nullptr) {
        str += ", ";
      }
    }
    str += "}";
    return str;
  }
};

class DisjointSet {
 public:
  Node* MakeSet(int key) {
    Node* node = new Node(key);
    Set* set = new Set();
    set->head = node;
    set->tail = node;
    node->set = set;
    set->weight++;
    return node;
  }

  void Union(Node* node1, Node* node2) {
    Set* set1 = node1->set;
    Set* set2 = node2->set;
    if (set1->weight < set2->weight) {
      Link(set1, set2);
    } else {
      Link(set2, set1);
    }
  }

  void Link(Set* src, Set* dest) {
    dest->tail->next = src->head;
    Node* node = src->head;
    while (node != nullptr) {
      node->set = dest;
      dest->weight++;
      node = node->next;
    }
    dest->tail = src->tail;
  }

  Node* FindSet(Node* node) { return node->set->head; }
};

void TestDisjointSet() {
  DisjointSet disjoint_set;
  std::vector<Node*> nodes(17, nullptr);
  for (int i = 1; i <= 16; i++) {
    nodes[i] = disjoint_set.MakeSet(i);
  }
  for (int i = 1; i <= 15; i += 2) {
    disjoint_set.Union(nodes[i], nodes[i + 1]);
  }

  // in this line, we now have:
  // {1, 2} {3, 4} {5, 6} {7, 8} {9, 10} {11, 12} {13, 14} {15, 16}

  for (int i = 1; i <= 13; i += 4) {
    disjoint_set.Union(nodes[i], nodes[i + 2]);
  }

  // in this line, we now have:
  // {1, 2, 3, 4} {5, 6, 7, 8} {9, 10, 11, 12} {13, 14, 15, 16}

  disjoint_set.Union(nodes[1], nodes[5]);
  disjoint_set.Union(nodes[11], nodes[13]);
  disjoint_set.Union(nodes[1], nodes[10]);
  std::cout << Set::ToString(disjoint_set.FindSet(nodes[2])->set) << std::endl;
  std::cout << Set::ToString(disjoint_set.FindSet(nodes[9])->set) << std::endl;
}

int main() { TestDisjointSet(); }

// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}
// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}
