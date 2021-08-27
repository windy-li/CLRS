#include "part6_graph_algorithms/344_breadth_first_search.h"

auto solution = Solution();

TEST(BFSTest, TestBFS) {
  auto g = Graph(7);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(1, 3);
  g.AddEdge(2, 3);
  g.AddEdge(3, 4);
  g.AddEdge(3, 5);
  solution.BFS(&g, 0);
  graph_util::PrintPath(g.vertices[0], g.vertices[5]);
  std::cout << std::endl;
  graph_util::PrintPath(g.vertices[0], g.vertices[6]);
  std::cout << std::endl;
  std::cout << Graph::ToString(&g) << std::endl;
}

/*
0 1 3 5
No path from 0 to 6

0: 1 2
1: 0 3
2: 0 3
3: 1 2 4 5
4: 3
5: 3
6:
 */

RUN_TESTS()
