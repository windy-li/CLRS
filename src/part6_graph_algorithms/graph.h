#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_H_

#include "clrs.h"
#include "part6_graph_algorithms/graph.h"
#include "part6_graph_algorithms/vertex.h"

struct Graph {
  int V;
  int E;
  std::vector<Vertex*> vertices;
  std::vector<std::list<Edge*>> adj;

  explicit Graph(int vertices_count)
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
    adj[end_id].push_back(e);
    E += 2;
  }

  friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (int i = 0; i < graph.V; ++i) {
      os << *graph.vertices[i];
      os << ": ";
      for (Edge* e : graph.adj[i]) {
        os << *graph.vertices[e->Other(i)];
        os << " ";
      }
      os << "\n";
    }
    return os;
  }

  static std::string ToString(Graph* graph) {
    std::string str;
    for (int i = 0; i < graph->V; i++) {
    }
    return "";
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_H_
