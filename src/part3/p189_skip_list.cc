#include "p189_skip_list.h"

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
