#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_DIGRAPH_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_DIGRAPH_H_

#include "clrs.h"
#include "part6_graph_algorithms/edge.h"
#include "part6_graph_algorithms/vertex.h"

struct Digraph {
  int V;
  int E;
  std::vector<Vertex*> vertices;
  std::vector<std::list<Edge*>> adj;

  explicit Digraph(int vertices_count)
      : V(vertices_count),
        E(0),
        vertices(std::vector<Vertex*>(vertices_count, nullptr)),
        adj(std::vector<std::list<Edge*>>(vertices_count, std::list<Edge*>())) {
    for (int i = 0; i < vertices_count; ++i) {
      vertices[i] = new Vertex(i);
    }
  }

  void AddEdge(int start_id, int end_id) {
    auto* e = new Edge(start_id, end_id);
    adj[start_id].push_back(e);
    E += 1;
  }

  static std::string ToString(Digraph* digraph) { return ""; }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_DIGRAPH_H_
