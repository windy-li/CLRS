#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_H_

#include "clrs.h"
#include "part6_graph_algorithms/vertex.h"

struct Graph {
  int V;
  int E;
  std::vector<Vertex*> vertices;
  std::vector<std::list<Edge*>> adj;
  std::vector<std::string> labels;

  explicit Graph(int vertices_count)
      : V(vertices_count),
        E(0),
        vertices(std::vector<Vertex*>(vertices_count, nullptr)),
        adj(std::vector<std::list<Edge*>>(vertices_count, std::list<Edge*>())) {
    for (int i = 0; i < vertices_count; ++i) {
      vertices[i] = new Vertex(i);
    }
  }

  Graph(int vertices_count, std::vector<std::string>& labels)
      : V(vertices_count),
        E(0),
        vertices(std::vector<Vertex*>(vertices_count, nullptr)),
        adj(std::vector<std::list<Edge*>>(vertices_count, std::list<Edge*>())),
        labels(std::vector<std::string>(labels)) {
    for (int i = 0; i < vertices_count; ++i) {
      vertices[i] = new Vertex(i);
    }
  }

  void AddEdge(int start_id, int end_id) {
    auto e = new Edge(start_id, end_id);
    adj[start_id].push_back(e);
    adj[end_id].push_back(e);
    E += 2;
  }

  void AddEdge(int start_id, int end_id, int weight) {
    auto e = new Edge(start_id, end_id, weight);
    adj[start_id].push_back(e);
    adj[end_id].push_back(e);
    E += 2;
  }

  std::vector<Edge*> AllEdges() {
    auto edges = std::vector<Edge*>(E, nullptr);
    int i = 0;
    for (int j = 0; j < V; ++j) {
      for (Edge* e : adj[j]) {
        edges[i++] = e;
      }
    }
    return edges;
  }

  static std::string ToString(const Graph* graph) {
    if (graph == nullptr) {
      return "nullptr";
    }
    auto str = std::string();
    for (int i = 0; i < graph->V; ++i) {
      str += Vertex::ToString(graph->vertices[i]) + ": ";
      for (Edge* e : graph->adj[i]) {
        str += std::to_string(e->Other(i)) + " ";
      }
      str += "\n";
    }
    return str;
  }

  friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    os << Graph::ToString(const_cast<Graph*>(&graph));
    return os;
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_H_
