#include "p189_skip_list2.h"

void PrintNode(const shared_ptr<Node>& node) {
  if (node == nullptr) {
    cout << "null";
  } else {
    cout << "{key: " << node->key;
    cout << ", forward: [";
    for (int i = 0; i < node->forward.size(); ++i) {
      cout << node->forward[i]->key;
      if (i != node->forward.size() - 1) {
        cout << ", ";
      }
    }
    cout << "]";
  }
  cout << endl;
}

int main() {
  SkipList list(3, 0.5);
  vector<int> keys = {3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
  for (int key : keys) {
    list.Insert(key);
  }
  PrintNode(list.Search(19));
    list.Remove(19);
  PrintNode(list.Search(19));
}
