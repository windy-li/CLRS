#include "part6_graph_algorithms/356_topological_sort.h"

TEST(TopologicalSortTest, TestTopologicalSort) {
  auto solution = Solution();
  auto dg = Digraph(5);
  dg.AddEdge(0, 1);
  dg.AddEdge(0, 3);
  dg.AddEdge(1, 2);
  dg.AddEdge(1, 3);
  dg.AddEdge(2, 4);
  dg.AddEdge(3, 2);
  dg.AddEdge(3, 4);
  std::cout << Digraph::ToString(&dg) << std::endl;
  std::list<Vertex*> sorted_vertices = solution.TopologicalSort(&dg);
  for (Vertex* v : sorted_vertices) {
    std::cout << std::to_string(v->id) + " ";
  }
}

RUN_TESTS()

/*
0: 1 3
1: 2 3
2: 4
3: 2 4
4:

0 1 3 2 4
 */
