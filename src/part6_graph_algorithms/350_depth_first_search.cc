#include "clrs.h"
#include "part6_graph_algorithms/edge.h"
#include "part6_graph_algorithms/graph.h"
#include "part6_graph_algorithms/vertex.h"

class Solution {
 public:
  Solution() : time_(0) {}

  void DFS(Graph* graph) {
    int V = graph->V;
    for (int i = 0; i < V; i++) {
      Vertex* u = graph->vertices[i];
      u->visited = false;
      u->pre = nullptr;
    }
    for (int i = 0; i < V; i++) {
      Vertex* u = graph->vertices[i];
      if (!u->visited) {
        Visit(graph, u);
      }
    }
  }

 private:
  int time_;

  void Visit(Graph* graph, Vertex* u) {
    time_++;
    u->d = time_;
    u->visited = true;
    for (Edge* e : graph->adj[u->id]) {
      Vertex* v = graph->vertices[e->Other(u->id)];
      if (!v->visited) {
        v->pre = u;
        Visit(graph, v);
      }
    }
    time_++;
    u->f = time_;
  }
};

void TestDepthFirstSearch() {
  Solution s;
  auto* graph = new Graph(6);
  graph->AddEdge(0, 1);
  graph->AddEdge(0, 2);
  graph->AddEdge(1, 3);
  graph->AddEdge(2, 3);
  graph->AddEdge(3, 4);
  graph->AddEdge(3, 5);
  s.DFS(graph);
}

int main() { TestDepthFirstSearch(); }
