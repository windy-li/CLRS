#include "clrs.h"

struct Vertex {
  bool visited;
  int d;
  Vertex* pre;
  int id;

  explicit Vertex(int id) : visited(false), d(0), pre(nullptr), id(id) {}

  friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
    os << vertex.id;
    return os;
  }
};

struct Edge {
  int start_id;
  int end_id;

  Edge(int start_id, int end_id) : start_id(start_id), end_id(end_id) {}

  int Other(int vertex_id) {
    if (vertex_id == start_id) {
      return end_id;
    } else if (vertex_id == end_id) {
      return start_id;
    } else {
      throw std::invalid_argument("no such vertex in this edge");
    }
  }
};

struct Graph {
  int V;
  int E;
  std::vector<Vertex*> vertices;
  std::vector<std::list<Edge*>> adj;

  explicit Graph(int vertices_count)
      : V(vertices_count),
        E(0),
        vertices(std::vector<Vertex*>(vertices_count, nullptr)),
        adj(std::vector<std::list<Edge*>>(vertices_count, std::list<Edge*>())) {
    for (int i = 0; i < vertices_count; ++i) {
      vertices[i] = new Vertex(i);
    }
  }

  void AddEdge(int start_id, int end_id) {
    auto* e = new Edge(start_id, end_id);
    adj[start_id].push_back(e);
    adj[end_id].push_back(e);
    E += 2;
  }

  friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (int i = 0; i < graph.V; ++i) {
      os << *graph.vertices[i];
      os << ": ";
      for (Edge* e : graph.adj[i]) {
        os << *graph.vertices[e->Other(i)];
        os << " ";
      }
      os << "\n";
    }
    return os;
  }
};

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

  void PrintPath(Vertex* src, Vertex* dst) {
    if (src == dst) {
      std::cout << *src << " ";
    } else {
      if (dst->pre == nullptr) {
        std::cout << "no path from " << *src << " to " << *dst << std::endl;
      } else {
        PrintPath(src, dst->pre);
        std::cout << *dst << " ";
      }
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
  solution.PrintPath(graph->vertices[0], graph->vertices[5]);
  std::cout << std::endl;
  solution.PrintPath(graph->vertices[0], graph->vertices[6]);
  std::cout << std::endl;
  std::cout << *graph << std::endl;
}

int main() { TestBreadthFirstSearch(); }
