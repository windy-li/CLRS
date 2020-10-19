#include "p162_binary_search_tree.h"

int main() {
  BinarySearchTree t;
  int keys[] = {6, 5, 7, 2, 5, 8};
  for (int key : keys) {
    t.Insert(key);
  }
  std::cout << t.root()->key << std::endl;
}
