#include "part3_data_structures/177_red_black_tree.h"

TEST(RedBlackTreeTest, TestRedBlackTree) {
  auto t = RedBlackTree();
  auto keys = std::vector<int>{11, 2, 14, 1, 7, 15, 5, 8};
  for (int key : keys) {
    t.Insert(key);
  }
  ASSERT_EQ(t.root()->key, 11);
}

RUN_TESTS()

/*
 * {key: 11, color: BLACK, parent: -1, left: 2, right: 14}
 */
