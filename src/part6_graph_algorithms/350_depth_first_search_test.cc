#include "part6_graph_algorithms/344_depth_first_search.h"

TEST(DepthFirstSearchTest, DepthFirstSearch) {
  auto graph = Graph(6);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);
  graph.AddEdge(3, 5);
  auto solution = Solution();
  solution.DFS(&graph);
}

RUN_TESTS()
