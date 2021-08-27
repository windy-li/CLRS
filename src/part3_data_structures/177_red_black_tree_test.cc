#include "part3_data_structures/177_red_black_tree.h"

TEST(RedBlackTreeTest, TestRedBlackTree) {
  auto t = RedBlackTree();
  std::vector<int> keys = {11, 2, 14, 1, 7, 15, 5, 8};
  for (int key : keys) {
    t.Insert(key);
  }
  printf("%d\n", t.root()->key);
}

RUN_TESTS()

/*
 * {key: 11, color: BLACK, parent: -1, left: 2, right: 14}
 */
