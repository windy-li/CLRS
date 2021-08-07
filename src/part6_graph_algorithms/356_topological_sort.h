#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_P356_TOPOLOGICAL_SORT_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_P356_TOPOLOGICAL_SORT_H_

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
    for (Vertex* v : digraph->vertices) {
      v->visited = false;
    }
    for (Vertex* v : digraph->vertices) {
      if (!v->visited) {
        Visit(digraph, v);
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

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_P356_TOPOLOGICAL_SORT_H_
