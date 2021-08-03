#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_P344_DEPTH_FIRST_SEARCH_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_P344_DEPTH_FIRST_SEARCH_H_

#include "clrs.h"
#include "part6_graph_algorithms/edge.h"
#include "part6_graph_algorithms/graph.h"
#include "part6_graph_algorithms/vertex.h"

class Solution {
 public:
  Solution() : time_(0) {}

  void DFS(Graph* graph) {
    for (Vertex* v : graph->vertices) {
      v->visited = false;
      v->predecessor = nullptr;
    }
    for (Vertex* v : graph->vertices) {
      if (!v->visited) {
        Visit(graph, v);
      }
    }
  }

 private:
  int time_;

  void Visit(Graph* graph, Vertex* u) {
    time_++;
    u->depth = time_;
    u->visited = true;
    for (Edge* e : graph->adj[u->id]) {
      Vertex* v = graph->vertices[e->Other(u->id)];
      if (!v->visited) {
        v->predecessor = u;
        Visit(graph, v);
      }
    }
    time_++;
    u->f = time_;
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_P344_DEPTH_FIRST_SEARCH_H_
