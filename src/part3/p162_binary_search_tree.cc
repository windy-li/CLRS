#include "p162_binary_search_tree.h"

int main() {
  BinarySearchTree tree;
  int keys[] = {6, 5, 7, 2, 5, 8};
  for (int key : keys) {
    tree.Insert(key);
  }
  cout << tree.root()->key << endl;
}
