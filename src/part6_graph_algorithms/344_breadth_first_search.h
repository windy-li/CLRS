#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_344_BREADTH_FIRST_SEARCH_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_344_BREADTH_FIRST_SEARCH_H_

#include "clrs.h"
#include "part6_graph_algorithms/edge.h"
#include "part6_graph_algorithms/graph.h"
#include "part6_graph_algorithms/graph_util.h"
#include "part6_graph_algorithms/vertex.h"

class Solution {
 public:
  void BreadthFirstSearch(Graph* graph, int src_id) {
    for (Vertex* v : graph->vertices) {
      v->visited = false;
      v->d = std::numeric_limits<int>::max();
      v->pre = nullptr;
    }
    Vertex* src = graph->vertices[src_id];
    src->visited = true;
    src->d = 0;
    std::queue<Vertex*> queue;
    queue.push(src);
    while (!queue.empty()) {
      Vertex* u = queue.front();
      queue.pop();
      for (Edge* e : graph->adj[u->id]) {
        Vertex* v = graph->vertices[e->Other(u->id)];
        if (!v->visited) {
          v->visited = true;
          v->d = u->d + 1;
          v->pre = u;
          queue.push(v);
        }
      }
      u->visited = true;
    }
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_344_BREADTH_FIRST_SEARCH_H_
