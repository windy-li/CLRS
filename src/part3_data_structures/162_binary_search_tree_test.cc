#include "part3_data_structures/162_binary_search_tree.h"

TEST(BinarySearchTreeTest, TestBinarySearchTree) {
  auto t = BinarySearchTree();
  auto keys = std::vector<int>{6, 5, 7, 2, 5, 8};
  for (int key : keys) {
    t.Insert(key);
  }
  ASSERT_EQ(t.root()->key, 6);
}

RUN_TESTS()
