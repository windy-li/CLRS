#include "clrs.h"

struct Vertex {
  bool visited;
  int d;
  Vertex* pre;
  int id;

  explicit Vertex(int id) : visited(false), d(0), pre(nullptr), id(id) {}
};

struct Edge {
  int Other(int id) { return 0; }

  Edge(int begin_id, int end_id) {}
};

struct Graph {
  int V;
  int E;
  std::vector<Vertex*> vertices;
  std::vector<std::list<Edge*>> adj;

  explicit Graph(int v_count)
      : V(v_count), E(0), vertices(std::vector<Vertex*>(v_count)), adj(std::vector<std::list<Edge*>>(v_count)) {
    for (int i = 0; i < v_count; ++i) {
      vertices[i] = new Vertex(i);
      adj[i] = std::list<Edge*>();
    }
  }

  void AddEdge(int begin_id, int end_id) {
    auto* e = new Edge(begin_id, end_id);
    adj[begin_id].push_back(e);
    adj[end_id].push_back(e);
    E += 2;
  }
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
        Vertex* v = graph->vertices[e->Other(u->id)];
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

void TestBreadthFirstSearch() {
  Solution s;
  auto* graph = new Graph(7);
  graph->AddEdge(0, 1);
  graph->AddEdge(0, 2);
  graph->AddEdge(1, 3);
  graph->AddEdge(2, 3);
  graph->AddEdge(3, 4);
  graph->AddEdge(3, 5);
  s.BreadthFirstSearch(graph, 0);
}

int main() { TestBreadthFirstSearch(); }
