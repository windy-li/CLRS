#include "part6_graph_algorithms/357_kosaraju_strongly_connected_components.h"

TEST(StronglyConnectedComponentsTest, TestStronglyConnectedComponents) {
  auto labels = std::vector<std::string>{"a", "b", "c", "depth", "e", "f", "g", "h"};
  auto dg = Digraph(8, labels);
  dg.AddEdge(0, 1);
  dg.AddEdge(1, 2);
  dg.AddEdge(1, 4);
  dg.AddEdge(2, 3);
  dg.AddEdge(3, 2);
  dg.AddEdge(3, 7);
  dg.AddEdge(4, 0);
  dg.AddEdge(4, 5);
  dg.AddEdge(5, 6);
  dg.AddEdge(6, 5);
  dg.AddEdge(6, 7);
  dg.AddEdge(7, 7);

  std::cout << Digraph::ToString(&dg) << std::endl;

  auto solution = Solution();
  solution.StronglyConnectedComponents(&dg);

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
