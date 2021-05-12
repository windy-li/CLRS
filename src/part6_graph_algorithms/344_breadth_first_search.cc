#include "clrs.h"

struct Vertex {
  bool visited;
  int d;
  Vertex* pre;
  int id;
};

struct Edge {
  int other(int id) { return 0; }
};

struct Graph {
  int V;
  std::vector<Vertex*> vertices;
  std::vector<std::list<Edge*>> adj;
};

class Solution {
 public:
  void BreadthFirstSearch(Graph* graph, int src_id) {
    int V = graph->V;
    for (int i = 0; i < V; ++i) {
      Vertex* u = graph->vertices[i];
      u->visited = false;
      u->d = std::numeric_limits<int>::max();
      u->pre = nullptr;
    }
    Vertex* src = graph->vertices[src_id];
    src->visited = true;
    src->d = 0;
    std::queue<Vertex*> q;
    q.push(src);
    while (!q.empty()) {
      Vertex* u = q.front();
      q.pop();
      for (auto* e : graph->adj[u->id]) {
        Vertex* v = graph->vertices[e->other(u->id)];
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
