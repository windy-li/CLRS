#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_344_BREADTH_FIRST_SEARCH_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_344_BREADTH_FIRST_SEARCH_H_

#include "clrs.h"
#include "part6_graph_algorithms/edge.h"
#include "part6_graph_algorithms/graph.h"
#include "part6_graph_algorithms/graph_util.h"
#include "part6_graph_algorithms/vertex.h"

class Solution {
 public:
  void BFS(Graph* graph, int src_id) {
    for (Vertex* v : graph->vertices) {
      v->visited = false;
      v->depth = std::numeric_limits<int>::max();
      v->predecessor = nullptr;
    }
    Vertex* src = graph->vertices[src_id];
    src->visited = true;
    src->depth = 0;
    auto q = std::queue<Vertex*>();
    q.push(src);
    while (!q.empty()) {
      Vertex* u = q.front();
      q.pop();
      for (Edge* e : graph->adj[u->id]) {
        Vertex* v = graph->vertices[e->Other(u->id)];
        if (!v->visited) {
          v->visited = true;
          v->depth = u->depth + 1;
          v->predecessor = u;
          q.push(v);
        }
      }
      u->visited = true;
    }
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_344_BREADTH_FIRST_SEARCH_H_
