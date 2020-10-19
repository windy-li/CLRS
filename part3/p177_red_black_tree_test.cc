#include "p177_red_black_tree.h"

int main() {
  RedBlackTree t;
  std::vector<int> keys = {11, 2, 14, 1, 7, 15, 5, 8};
  for (int key : keys) {
    t.Insert(key);
  }
  std::cout << t.root()->key << std::endl;
}

/*
 * {key: 11, color: BLACK, parent: -1, left: 2, right: 14}
 */
