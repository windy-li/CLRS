#include "p177_red_black_tree.h"

int main() {
  RedBlackTree tree;
  vector<int> keys = {11, 2, 14, 1, 7, 15, 5, 8};
  for (int key : keys) {
    tree.Insert(key);
  }
  cout << tree.root()->key << endl;
}

/*
 * {key: 11, color: BLACK, parent: -1, left: 2, right: 14}
 */
