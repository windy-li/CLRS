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
  std::vector<std::string> labels;

  explicit Digraph(int vertices_count)
      : V(vertices_count),
        E(0),
        vertices(std::vector<Vertex*>(vertices_count, nullptr)),
        adj(std::vector<std::list<Edge*>>(vertices_count, std::list<Edge*>())) {
    for (int i = 0; i < vertices_count; ++i) {
      vertices[i] = new Vertex(i);
    }
  }

  Digraph(int vertices_count, std::vector<std::string>& labels)
      : V(vertices_count),
        E(0),
        vertices(std::vector<Vertex*>(vertices_count, nullptr)),
        adj(std::vector<std::list<Edge*>>(vertices_count, std::list<Edge*>())),
        labels(std::vector<std::string>(labels)) {
    for (int i = 0; i < vertices_count; ++i) {
      vertices[i] = new Vertex(i, labels[i]);
    }
  }

  void AddEdge(int start_id, int end_id) {
    auto* e = new Edge(start_id, end_id);
    adj[start_id].push_back(e);
    E += 1;
  }

  void AddEdge(int start_id, int end_id, int weight) {
    auto* e = new Edge(start_id, end_id, weight);
    adj[start_id].push_back(e);
    E += 1;
  }

  std::vector<Edge*> AllEdges() {
    std::vector<Edge*> edges(E);
    int i = 0;
    for (int j = 0; j < V; j++) {
      for (Edge* e : adj[j]) {
        edges[i++] = e;
      }
    }
    return edges;
  }

  Digraph* Transpose() {
    Digraph* t_digraph;
    if (labels.empty()) {
      t_digraph = new Digraph(V);
    } else {
      t_digraph = new Digraph(V, labels);
    }
    for (int i = 0; i < V; i++) {
      for (Edge* e : adj[i]) {
        t_digraph->AddEdge(e->Other(i), i);
      }
    }
    return t_digraph;
  }

  static std::string ToString(Digraph* digraph) {
    if (digraph == nullptr) {
      return "nullptr";
    }
    std::string str;
    for (int i = 0; i < digraph->V; i++) {
      str += Vertex::ToString(digraph->vertices[i]) + ": ";
      for (Edge* e : digraph->adj[i]) {
        str += Vertex::ToString(digraph->vertices[e->Other(i)]) + " ";
      }
      str += "\n";
    }
    return str;
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_DIGRAPH_H_
