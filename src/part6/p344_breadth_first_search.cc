#include "../clrs.h"
#include "graph.h"

class Solution {
 public:
  void BreadthFirstSearch(Graph* g, int src_id) {
    for (int i = 0; i < g->v; i++) {
      Vertex* u = g->vertices[i];
      u->visited = false;
      u->d = INT_MAX;
      u->pre = nullptr;
    }
    Vertex* src = g->vertices[src_id];
    src->visited = true;
    src->d = 0;
    std::queue<Vertex*> q;
    q.push(src);
    while (!q.empty()) {
      Vertex* u = q.front();
      q.pop();
      for (Edge* e : g->adj[u->id]) {
        Vertex* v = g->vertices[e->Other(u->id)];
        if (!v->visited) {
          v->visited = true;
          v->d = u->d + 1;
          v->pre = u;
          q.push(v);
        }
      }
      u->visited = true;
    }
  }
};
