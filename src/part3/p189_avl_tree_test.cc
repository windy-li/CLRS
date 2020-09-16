#include "p189_avl_tree.h"

int main() {
  AvlTree t;
  std::vector<int> keys = {9, 5, 10, 0, 6, 11, -1, 1, 2};
  for (int key : keys) {
    t.Insert(key);
  }
  std::cout << t.IsAvlStructure() << std::endl;
  std::cout << t.root() << std::endl;
}
