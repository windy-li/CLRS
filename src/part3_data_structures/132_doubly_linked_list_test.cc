#include "clrs.h"

struct Node {
  int key;
  Node* prev;
  Node* next;

  explicit Node(int key) : key(key), prev(nullptr), next(nullptr) {}

  // TODO
  static std::string ToString(const Node* node) {
    if (node == nullptr) {
      return "nullptr";
    }
    return "";
  }

  friend std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << Node::ToString(const_cast<Node*>(&node));
    return os;
  }
};

class LinkedList {
 public:
  LinkedList() : head_(nullptr) {}

  Node* head() { return head_; }

  Node* Search(int key) {
    Node* node = head_;
    while (node != nullptr && node->key != key) {
      node = node->next;
    }
    return node;
  }

  void PushFront(int k) {
    auto node = new Node(k);
    node->prev = nullptr;
    node->next = head_;
    if (head_ != nullptr) {
      head_->prev = node;
    }
    head_ = node;
  }

  void RemoveKey(int k) {
    Node* x = Search(k);
    if (x != nullptr) {
      Remove(x);
    }
  }

  void Remove(Node* node) {
    if (node->prev != nullptr) {
      node->prev->next = node->next;
    } else {
      head_ = node->next;
    }
    if (node->next != nullptr) {
      node->next->prev = node->prev;
    }
  }

  void Reverse() {
    Node* tmp = nullptr;
    Node* current = head_;
    while (current != nullptr) {
      tmp = current->prev;
      current->prev = current->next;
      current->next = tmp;
      current = current->prev;
    }
    if (tmp != nullptr) {
      head_ = tmp->prev;
    }
  }

  // TODO
  static std::string ToString(const LinkedList* list) {
    if (list == nullptr) {
      return "nullptr";
    }
    return "";
  }

  friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    os << LinkedList::ToString(const_cast<LinkedList*>(&list));
    return os;
  }

 private:
  Node* head_;
};

void PrintNode(Node* node) {
  if (node == nullptr) {
    std::cout << "null" << std::endl;
    return;
  }
  std::cout << "{ key: " << node->key;
  if (node->prev != nullptr) {
    std::cout << ", prev: " << node->prev->key;
  }
  if (node->next != nullptr) {
    std::cout << ", next: " << node->next->key;
  }
  std::cout << " }";
}

void PrintLinkedList(LinkedList* list) {
  Node* node = list->head();
  while (node != nullptr) {
    std::cout << node->key;
    if (node->next != nullptr) {
      std::cout << " -> ";
    }
    node = node->next;
  }
}

void TestLinkedList() {
  auto list = LinkedList();
  list.PushFront(1);
  list.PushFront(4);
  list.PushFront(16);
  list.PushFront(9);
  list.PushFront(25);
  Node* node1 = list.Search(4);
  if (node1 != nullptr) {
    PrintNode(node1);
  } else {
    std::cout << "null" << std::endl;
  }
  PrintLinkedList(&list);
  list.Reverse();
  PrintLinkedList(&list);
  list.RemoveKey(4);
  Node* node2 = list.Search(4);
  if (node2 != nullptr) {
    PrintNode(node2);
  } else {
    std::cout << "null" << std::endl;
  }
  PrintLinkedList(&list);
}

int main() { TestLinkedList(); }
