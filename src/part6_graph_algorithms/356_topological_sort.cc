#include "clrs.h"
#include "part6_graph_algorithms/digraph.h"
#include "part6_graph_algorithms/edge.h"
#include "part6_graph_algorithms/vertex.h"

class Solution {
 public:
  Solution() : vertices_(std::list<Vertex*>()) {}

  std::list<Vertex*> TopologicalSort(Digraph* digraph) {
    DFS(digraph);
    return vertices_;
  }

 private:
  std::list<Vertex*> vertices_;

  void DFS(Digraph* digraph) {
    for (int i = 0; i < digraph->V; i++) {
      Vertex* u = digraph->vertices[i];
      u->visited = false;
    }
    for (int i = 0; i < digraph->V; i++) {
      Vertex* u = digraph->vertices[i];
      if (!u->visited) {
        Visit(digraph, u);
      }
    }
  }

  void Visit(Digraph* digraph, Vertex* u) {
    u->visited = true;
    for (Edge* e : digraph->adj[u->id]) {
      Vertex* v = digraph->vertices[e->Other(u->id)];
      if (!v->visited) {
        Visit(digraph, v);
      }
    }
    vertices_.push_front(u);
  }
};

void Test() {
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

int main() { Test(); }

/*
0: 1 3
1: 2 3
2: 4
3: 2 4
4:
0 1 3 2 4
 */
