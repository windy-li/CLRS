#include "part6_graph_algorithms/344_breadth_first_search.h"

Solution solution;

TEST(BreadthFirstSearchTest, TestBreadthFirstSearch) {
  auto* graph = new Graph(7);
  graph->AddEdge(0, 1);
  graph->AddEdge(0, 2);
  graph->AddEdge(1, 3);
  graph->AddEdge(2, 3);
  graph->AddEdge(3, 4);
  graph->AddEdge(3, 5);
  solution.BreadthFirstSearch(graph, 0);
  graph_util::PrintPath(graph->vertices[0], graph->vertices[5]);
  std::cout << std::endl;
  graph_util::PrintPath(graph->vertices[0], graph->vertices[6]);
  std::cout << std::endl;
  std::cout << Graph::ToString(graph) << std::endl;
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
