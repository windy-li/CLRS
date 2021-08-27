#include "part3_data_structures/189_skip_list.h"

void PrintNode(const Node* node) {
  if (node == nullptr) {
    printf("null");
  } else {
    printf("{ key: %d, forward: [", node->key);
    for (int i = 0; i < node->forward.size(); ++i) {
      printf("%d", node->forward[i]->key);
      if (i != node->forward.size() - 1) {
        printf(", ");
      }
    }
    printf("] }");
  }
  printf("\n");
}

TEST(TestSkipList, SkipListTest) {
  auto list = SkipList(3, 0.5);
  std::vector<int> keys = {3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
  for (int key : keys) {
    list.Insert(key);
  }
  PrintNode(list.Search(19));
  list.Remove(19);
  PrintNode(list.Search(19));
}

RUN_TESTS()
