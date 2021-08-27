#include "part3_data_structures/189_avl_tree.h"

TEST(AvlTreeTest, TestAvlTree) {
  std::vector<int> keys = {9, 5, 10, 0, 6, 11, -1, 1, 2};
  auto t = AvlTree();
  for (int key : keys) {
    t.InsertKey(key);
  }
  ASSERT_TRUE(t.IsAvlStructure());
  ASSERT_EQ(t.root()->key, 9);
}

RUN_TESTS()
