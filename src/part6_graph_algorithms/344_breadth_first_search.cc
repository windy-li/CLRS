#include "clrs.h"
#include "part6_graph_algorithms/edge.h"
#include "part6_graph_algorithms/graph.h"
#include "part6_graph_algorithms/graph_util.h"
#include "part6_graph_algorithms/vertex.h"

class Solution {
 public:
  void BreadthFirstSearch(Graph* graph, int src_id) {
    for (int i = 0; i < graph->V; ++i) {
      Vertex* u = graph->vertices[i];
      u->visited = false;
      u->d = std::numeric_limits<int>::max();
      u->pre = nullptr;
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

void TestBreadthFirstSearch() {
  Solution solution;
  auto* graph = new Graph(7);
  graph->AddEdge(0, 1);
  graph->AddEdge(0, 2);
  graph->AddEdge(1, 3);
  graph->AddEdge(2, 3);
  graph->AddEdge(3, 4);
  graph->AddEdge(3, 5);
  solution.BreadthFirstSearch(graph, 0);
  graph_util::PrintPath(graph->vertices[0], graph->vertices[5]);
  std::cout << std::endl;
  graph_util::PrintPath(graph->vertices[0], graph->vertices[6]);
  std::cout << std::endl;
  std::cout << Graph::ToString(graph) << std::endl;
}

int main() { TestBreadthFirstSearch(); }

/*
0 1 3 5
No path from 0 to 6

0: 1 2
1: 0 3
2: 0 3
3: 1 2 4 5
4: 3
5: 3
6:
 */
