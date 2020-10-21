#include "clrs.h"

struct Node {
  int key;
  std::vector<Node*> forward;

  Node(int key, int level) : key(key), forward(std::vector<Node*>(level + 1, nullptr)) {}
};

class SkipList {
 public:
  SkipList(int max_level, double p)
      : head_(new Node(-1, max_level)), max_level_(max_level), p_(p), current_level_(0) {}

  void Insert(int key) {
    Node* current_node = head_;
    std::vector<Node*> update_list(max_level_ + 1, nullptr);
    for (int i = current_level_; i >= 0; i--) {
      while (current_node->forward[i] != nullptr && current_node->forward[i]->key < key) {
        current_node = current_node->forward[i];
      }
      update_list[i] = current_node;
    }
    current_node = current_node->forward[0];
    if (current_node == nullptr || current_node->key != key) {
      int random_level = RandomLevel();
      if (random_level > current_level_) {
        for (int i = current_level_ + 1; i <= random_level; i++) {
          update_list[i] = head_;
        }
        current_level_ = random_level;
      }
      Node* node = new Node(key, random_level);
      for (int i = 0; i <= random_level; i++) {
        node->forward[i] = update_list[i]->forward[i];
        update_list[i]->forward[i] = node;
      }
    }
  }

  Node* Search(int key) {
    Node* current = head_;
    for (int i = current_level_; i >= 0; i--) {
      while (current->forward[i] != nullptr && current->forward[i]->key < key) {
        current = current->forward[i];
      }
    }
    current = current->forward[0];
    if (current != nullptr && current->key == key) {
      return current;
    }
    return nullptr;
  }

  void Remove(int key) {
    Node* current = head_;
    std::vector<Node*> update(max_level_ + 1, nullptr);
    for (int i = current_level_; i >= 0; i--) {
      while (current->forward[i] != nullptr && current->forward[i]->key < key) {
        current = current->forward[i];
      }
      update[i] = current;
    }
    current = current->forward[0];
    if (current != nullptr && current->key == key) {
      for (int i = 0; i <= current_level_; i++) {
        if (update[i]->forward[i] != current) {
          break;
        }
        update[i]->forward[i] = current->forward[i];
      }
      while (current_level_ > 0 && head_->forward[current_level_] == nullptr) {
        current_level_--;
      }
    }
  }

 private:
  Node* head_;
  int max_level_;
  double p_;
  int current_level_;

  int RandomLevel() {
    int tmp = 0;
    while (clrs::Random() < p_ && tmp < max_level_) {
      tmp++;
    }
    return tmp;
  }
};

void PrintNode(Node* node) {
  if (node == nullptr) {
    std::cout << "null";
  } else {
    std::cout << "{key: " << node->key;
    std::cout << ", forward: [";
    for (int i = 0; i < node->forward.size(); ++i) {
      std::cout << node->forward[i]->key;
      if (i != node->forward.size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "]";
  }
  std::cout << std::endl;
}

int main() {
  SkipList list(3, 0.5);
  std::vector<int> keys = {3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
  for (int key : keys) {
    list.Insert(key);
  }
  PrintNode(list.Search(19));
  list.Remove(19);
  PrintNode(list.Search(19));
}
