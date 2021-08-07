#include "part6_graph_algorithms/357_kosaraju_strongly_connected_components.h"

TEST(StronglyConnectedComponentsTest, TestStronglyConnectedComponents) {
  std::vector<std::string> labels = {"a", "b", "c", "depth", "e", "f", "g", "h"};
  Digraph digraph(8, labels);
  digraph.AddEdge(0, 1);
  digraph.AddEdge(1, 2);
  digraph.AddEdge(1, 4);
  digraph.AddEdge(2, 3);
  digraph.AddEdge(3, 2);
  digraph.AddEdge(3, 7);
  digraph.AddEdge(4, 0);
  digraph.AddEdge(4, 5);
  digraph.AddEdge(5, 6);
  digraph.AddEdge(6, 5);
  digraph.AddEdge(6, 7);
  digraph.AddEdge(7, 7);

  std::cout << Digraph::ToString(&digraph) << std::endl;

  Solution solution;
  solution.StronglyConnectedComponents(&digraph);

  std::vector<std::list<Vertex*>> components = solution.components();
  size_t count = components.size();
  std::cout << count << " components" << std::endl;

  for (std::list<Vertex*>& vertices : components) {
    for (Vertex* v : vertices) {
      std::cout << Vertex::ToString(v) + " ";
    }
    std::cout << std::endl;
  }

  std::cout << solution.Connected(0, 4) << std::endl;
  std::cout << solution.Connected(1, 7) << std::endl;
}

RUN_TESTS()

/*
a: b
b: c e
c: depth
depth: c h
e: a f
f: g
g: f h
h: h

4 components
a b e
f g
c depth
h
1
0
 */
