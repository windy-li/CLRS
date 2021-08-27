#include "part3_data_structures/189_treap.h"

TEST(TreapTest, TestTreap) {
  auto t = Treap();
  std::vector<int> keys{5, 3, 2, 4, 7, 6, 1, 8};
  for (int key : keys) {
    t.Insert(key);
  }
  t.Inorder(t.root());
  ASSERT_EQ(t.Search(3)->key, 3);
  t.Remove(3);
  ASSERT_EQ(t.Search(3), nullptr);
}

RUN_TESTS()
