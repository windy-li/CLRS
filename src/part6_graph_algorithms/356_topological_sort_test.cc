#include "part6_graph_algorithms/356_topological_sort.h"

TEST(TopologicalSortTest, TestTopologicalSort) {
  Solution solution;
  Digraph digraph(5);
  digraph.AddEdge(0, 1);
  digraph.AddEdge(0, 3);
  digraph.AddEdge(1, 2);
  digraph.AddEdge(1, 3);
  digraph.AddEdge(2, 4);
  digraph.AddEdge(3, 2);
  digraph.AddEdge(3, 4);
  std::cout << Digraph::ToString(&digraph) << std::endl;
  std::list<Vertex*> sorted_vertices = solution.TopologicalSort(&digraph);
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
