#include "part3_data_structures/189_avl_tree.h"

TEST(AvlTreeTest, TestAvlTree) {
  std::vector<int> keys = {9, 5, 10, 0, 6, 11, -1, 1, 2};
  AvlTree tree;
  for (int key : keys) {
    tree.InsertKey(key);
  }
  ASSERT_TRUE(tree.IsAvlStructure());
  ASSERT_EQ(tree.root()->key, 9);
}

RUN_TESTS()
